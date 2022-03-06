#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::stack<std::pair<int, int>> S;
  for (int i = 0; i < n; ++i) {
    int mn = a[i], mx = a[i];
    while (!S.empty()) {
      auto [l, r] = S.top();
      if (r < mn) break;
      S.pop();
      mx = std::max(mx, r);
      mn = std::min(mn, l);
    }
    S.push({mn, mx});
  }
  std::cout << S.size() << '\n';
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
