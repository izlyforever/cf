#define COLORS \
  X(red) \
  X(blue) \
  X(green)

#define X(a) a,
  enum Color { COLORS };
#undef X

#define X(a) #a,
  static char *ColorStrings[] = { COLORS };
#undef X

#include <stdio.h>

int main() {
  enum Color x = red;
  printf("%s\n", ColorStrings[x]);
  return 0;
}
