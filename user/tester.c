// Do not modify this file. It will be replaced by the grading scripts
// when checking your project.

#include "types.h"
#include "stat.h"
#include "user.h"

void thread(void* arg)
{
  printf(1, "My argument is %d.\n", *((int*)arg));
  int i;
  for(i = 0; i < 100; ++i){
  malloc(4096);
  }
}

int
main(int argc, char *argv[])
{
  int arg = 5;
  if(thread_create(thread, &arg) < 0) {
    printf(1, "Failed to create thread\n");
  }
  printf(1, "Joining thread\n");
  int i;
  for(i = 0; i < 100; ++i){
  malloc(4096);
  }
  thread_join();
  exit();
  return 0;
}
