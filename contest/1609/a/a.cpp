#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  LL t = 1;
  for (auto &x : a) {
    std::cin >> x;
    t *= x & -x;
    x /= x & -x;
  }
  auto mx = *std::max_element(a.begin(), a.end());
  auto sm = std::accumulate(a.begin(), a.end(), 0);
  std::cout << t * mx + sm - mx << '\n';
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