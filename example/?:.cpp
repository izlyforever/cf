#include <bits/stdc++.h>

int main() {
  {
    int x = 0;
    int y = 0;
    int z = (y * y >= 0 ? x++ : x++) > 0 ? 2 : 3;
    std::cout << x << ' ' << y << ' ' << z << '\n';
  }
  {
    int x = 0;
    int y = 0;
    int z = y * y >= 0 ? x++ : (x++ > 0 ? 2 : 3);
    std::cout << x << ' ' << y << ' ' << z << '\n';
  }
  {
    int x = 0;
    int y = 0;
    int z = y * y >= 0 ? x++ : x++ > 0 ? 2 : 3;
    std::cout << x << ' ' << y << ' ' << z << '\n';
  }
  return 0;
}