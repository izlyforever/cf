#include <bits/stdc++.h>
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  int s = std::accumulate(a.begin(), a.end(), 0);
  if (s == n) std::cout << 0 << '\n';
  else if (s < n) std::cout << 1 << '\n';
  else std::cout << s - n << '\n';
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
