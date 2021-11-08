#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int, int>> a(n);
  int s = 0;
  for (auto& [id, x] : a) {
    std::cin >> id >> x;
    s += x;
  }
  std::sort(a.begin(), a.end());
  for (auto [id, x] : a) {
    if (id == m) {
      x = std::max(x, 60);
    } else {
      if (x * n >= s) x = std::max(0, x - 2);
    }
    std::cout << x << ' ';
  }
  std::cout << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}