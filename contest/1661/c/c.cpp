#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> h(n);
  for (auto &x : h) std::cin >> x;
  auto mx = *std::max_element(h.begin(), h.end());
  auto sm = std::accumulate(h.begin(), h.end(), 0LL);
  auto f = [&](int x) -> LL {
    int cnt = 0;
    for (auto t : h) {
      if (x - t == 1) {
        ++cnt;
      }
    }
    LL tot = 1LL * n * x - sm;
    if (cnt <= tot - 2 * cnt) {
      return tot / 3 * 2 + tot % 3;
    }
    return 2 * cnt - 1;
  };
  std::cout << std::min(f(mx), f(mx + 1)) << '\n';
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
