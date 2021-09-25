// preload.cpp
#include <iostream>

struct Goodbye {
  Goodbye() {std::cout << "Fake Add start!\n";}
  ~Goodbye() {std::cout << "Goodbye!\n";}
} goodbye;

int Add(int x, int y) {
  return x * y;
}
