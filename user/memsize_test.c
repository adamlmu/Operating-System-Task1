#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void memsize_test(void)
{
  printf("memsize test\n");
  printf("before malloc: %d\n", memsize());
  void *memory = malloc(20000);
  printf("after malloc: %d\n", memsize());
  free(memory);
  printf("after free: %d\n", memsize());
}

int main(void)
{
  memsize_test();
  exit(0, "");
}