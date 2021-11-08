#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;
#include "Add.hpp"

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << "Please input two integers:" << std::endl;
  int a, b;
  std::cin >> a >> b;
  std::cout << "a = " << a << ", b = " << b << std::endl;
  cerr(Add(a, b));
  cerr(Sub(a, b));
  return 0;
}