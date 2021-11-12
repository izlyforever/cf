#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  auto f = [](int n, int x, int y) -> std::vector<int> {
    if (n < x + y - 1) return {-1};
    std::vector<int> ans;
    while (n > 0 && x + y - 1 < n) {
      for (int i = n - x + 1; i <= n; ++i) ans.emplace_back(i);
      --y;
      n -= x;
    }
    if (y <= 0) return {-1};
    for (int i = y; i <= n; ++i) ans.emplace_back(i);
    for (int i = y - 1; i > 0; --i) ans.emplace_back(i);
    return ans;
  };
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> ans;
  if (x < y) {
    ans = f(n, y, x);
    for (auto& x : ans) if (x != -1) x = n + 1 - x;
  } else {
    ans = f(n, x, y);
  }
  for (auto& x : ans) std::cout << x << ' ';
  std::cout << '\n';
  return 0;
}