#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int s = 0;
  {
    int i;
    for (i = 0; i < n; ++i) {
      s += i ^ n;
    }
  }
  printf("%d\n", s);
  /* 注释测试 */
  /* 中文测试 */
  printf("垃圾上海\n");
  return 0;
}