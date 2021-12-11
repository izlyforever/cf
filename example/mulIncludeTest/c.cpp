#include "c.h"

int addC(int y) {
  static int x = 0;
  return --x + y;
}