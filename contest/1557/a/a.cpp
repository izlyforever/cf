#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  int x = *std::max_element(a.begin(), a.end());
  LL s = std::accumulate(a.begin(), a.end(), 0LL);
  std::cout << std::fixed << x + (s - x) * 1.0 / (n - 1) << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  std::cout.precision(12);
  while (cas--) {
    solve();
  }
  return 0;
}