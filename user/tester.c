#include "types.h"
#include "user.h"


volatile int global[2] = {0, 1};
lock_t lock;

#define assert(x) if (x) {} else { \
   printf(1, "%s: %d ", __FILE__, __LINE__); \
   printf(1, "assert failed (%s)\n", # x); \
   printf(1, "TEST FAILED\n"); \
   kill(ppid); \
   exit(); \
}

void worker(void *arg_ptr);

int
main(int argc, char *argv[])
{
   lock_init(&lock);
   thread_create(&worker, NULL);
   sleep(0);
   
   lock_acquire(&lock);
   global[0] = 4;
   sleep(2);
   global[1] = 3;
   lock_release(&lock);
   
   thread_join();
   
   printf(1, "Global array: [%d, %d]\n", global[0], global[1]);
   
   exit();
}

void
worker(void *arg_ptr) {
  lock_acquire(&lock);
  global[0] = 10;
  global[1] = 11;
  lock_release(&lock);
}
