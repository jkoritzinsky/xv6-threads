// Do not modify this file. It will be replaced by the grading scripts
// when checking your project.

#include "types.h"
#include "stat.h"
#include "user.h"

void thread(void* arg)
{
  printf(1, "My argument is %d.\n", *((int*)arg));
}

int
main(int argc, char *argv[])
{
  int arg = 5;
  if(thread_create(thread, &arg) < 0) {
    printf(1, "Failed to create thread\n");
  }
  printf(1, "Joining thread\n");
  thread_join();
  exit();
  return 0;
}
