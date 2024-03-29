#include <bits/stdc++.h>
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> h(n);
  for (auto& x : h) std::cin >> x;
  std::sort(h.begin(), h.end());
  int mx = INT_MAX, x = 0;
  for (int i = 1; i < n; ++i) if (mx > h[i] - h[i - 1]) {
    x = i;
    mx = h[i] - h[i - 1];
  }
  std::cout << h[x - 1] << ' ';
  for (int i = x + 1; i < n; ++i) std::cout << h[i] << ' ';
  for (int i = 0; i < x - 1; ++i) std::cout << h[i] << ' ';
  std::cout << h[x] << '\n';
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
