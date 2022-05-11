#include <stdio.h>

int d = 100;
int x = 200;
void p1(void);

int main(void) {
  p1();
  printf("d=%d, x=%d\n", d, x);
  return 0;
}

// gcc pMain.c p1.c -o main
