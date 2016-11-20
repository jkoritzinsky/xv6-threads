#include "types.h"
#include "user.h"
#include "x86.h"

int thread_create(void (*start_routine)(void*), void* arg)
{
  void* stack = malloc(4096);
  return clone(start_routine, arg, stack);
}

int thread_join()
{
  void* stack;
  int retVal = join(&stack);
  free(stack);
  return retVal;
}

void lock_init(lock_t * lock)
{
  lock->locked = 0;
}
void lock_acquire(lock_t * lk)
{
  while(xchg(&lk->locked, 1) != 0);
}

void lock_release(lock_t * lk)
{
  xchg(&lk->locked, 0);
}
