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
  return 0;
}