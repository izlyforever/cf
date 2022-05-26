#include <stdio.h>

typedef struct {
  int a[0];
} test;

struct test2 {
  int a[0];
} A;

union example {
  int a[5];
  char b;
  double c;
};

int main(void) {
  printf("%d\n", sizeof (test));
  printf("%d\n", sizeof (struct test2));
  printf("%d\n", sizeof (A));
  struct test2 B;
  printf("%d\n", sizeof (B));
  printf("%d\n", sizeof (example));

  return 0;
}
