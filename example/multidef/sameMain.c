#include <stdio.h>

union {
  struct {
    int d;
    int x;
  } point;
  double dx;
} A;

int main(void) {
  A.dx = 1.0;
  printf("d=%d, x=%d\n", A.point.d, A.point.x);
  return 0;
}

// 它 和 p1.c pMain.c 组合是一样的原理：
// 强符号和弱符号规则 https://www.liqinglin0314.com/article/466
// p1 中的指令是 8 个字节的赋值，然后 d, x 它们的地址又是挨着的 且 p1 中用的地址是 main 中 d 的地址，所以都改变了
