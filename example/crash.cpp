#include <bits/stdc++.h>

// use VS  debug -> save dump as crash.dmp
// https://blog.csdn.net/gdnh22a/article/details/110437968 for detail

int divCrash(int x) {
  int ans = 100 / x;
  return ans;
}

int main() {
  std::cout << "input zeros to general crash" << std::endl;
  int x;
  std::cin >> x;
  std::cout << divCrash(x) << std::endl;
  return 0;
}
