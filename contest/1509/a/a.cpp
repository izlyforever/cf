#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a[2];
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      a[x & 1].emplace_back(x);
    }
    for (auto x : a[0]) std::cout << x << ' ';
    for (auto x : a[1]) std::cout << x << ' ';
    std::cout << '\n';
  }
  return 0;
}