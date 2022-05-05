#include <stdio.h>

int f();

int main(void) {
  printf("%d\n", f(1, 2, 3));

  return 0;
}

int f(int a, int b, int c) {
  return a * b + c;
}
