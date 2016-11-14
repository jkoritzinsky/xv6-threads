#include "types.h"
#include "user.h"

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

int lock_init(lock_t * lock){return 0;}
int lock_acquire(lock_t * lock){return 0;}
int lock_release(lock_t * lock){ return 0;}
