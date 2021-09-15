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
    std::vector<int> a(n), b;
    for (auto& x : a) std::cin >> x;
    for (int i = 0; i < n / 2; ++i) {
      b.emplace_back(a[i]);
      b.emplace_back(a[n - 1 - i]);
    }
    if (n % 2 == 1) b.emplace_back(a[n / 2]);
    for (auto& x : b) std::cout << x << " ";
    std::cout << "\n";
  }
  return 0;
}