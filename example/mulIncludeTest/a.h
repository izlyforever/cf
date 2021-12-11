#pragma once 

int add(int y) {
  static int x = 0;
  return x + y;
}
