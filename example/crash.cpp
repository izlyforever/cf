#include <bits/stdc++.h>

int divCrash(int x) {
  return 100 / x;
}

int main() {
  std::cout << "input zeros to general crash" << std::endl;
  int x;
  std::cin >> x;
  std::cout << divCrash(x) << std::endl;
  return 0;
}
