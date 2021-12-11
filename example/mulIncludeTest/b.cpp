#include "b.h"

int addB(int y) {
  static int x = 0;
  return ++x + y;
}