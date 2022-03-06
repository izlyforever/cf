#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool check(int x) {
  return x % 10 != 3 && x % 3 != 0;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::vector<int> a;
  int now = 1;
  while (a.size() < 1000) {
    while (!check(now)) ++now;
    a.emplace_back(now++);
  }
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int x;
    std::cin >> x;
    std::cout << a[x - 1] << '\n';
  }
  return 0;
}
