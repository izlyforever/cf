#include <stdio.h>

// C 不支持缺省参数
int f(int x = 0) {
  return x ^ 1;
}
int main() {
  printf("%d\n", f());
  printf("%d\n", f(1));
  return 0;
}