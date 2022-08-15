#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
constexpr int INF = 1e9;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  auto f = [&](int m) -> bool {
    auto b = a;
    int cnt = 0;
    for (auto &x : b) if (2 * x < m) {
      x = INF;
      ++cnt;
    }
    bool one = false, two = false;
    for (int i = 0; i < n; ++i) if (b[i] >= m) {
      one = true;
      break;
    }
    for (int i = 1; i < n; ++i) if (b[i] >= m && b[i - 1] >= m) {
      two = true;
      break;
    }
    cnt += !one + !two;
    return cnt <= k;
  };

  int l = 1, r = INF;
  while (l <= r) {
    int m = (l + r) / 2;
    if (f(m)) l = m + 1;
    else r = m - 1;
  }
  std::cout << r << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
