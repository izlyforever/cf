#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;
  auto f = [&](int i) -> std::pair<int, int> {
    int x = b[i] - a[i], y = a[i] - 2 * x;
    return {x, y}; // 只要 x >= 0， y 就不会越界
  };
  if (n == 1) return a[0] + b[0] == 0;
  if (b[0] - a[0] < 1) return false;
  LL sWin = 0, sDraw = 0;
  int maxDraw = 0;
  for (int i = 0; i < n; ++i) {
    auto [x, y] = f(i);
    if (x < 0 || y < 0) return false;
    sWin += x;
    sDraw += y;
    maxDraw = std::max(maxDraw, y);
  }
  if (n == 2 && sWin != b[0] - a[0]) return false;
  return sDraw % 2 == 0 && maxDraw * 2 <= sDraw && sWin >= n - 1;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES\n" : "NO\n");
  }
  return 0;
}