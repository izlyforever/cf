#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  std::vector<LL> p(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> p[i];
  auto sm = p;
  for (int i = n; i > 0; --i) sm[i - 1] += sm[i];
  std::vector<LL> ans(n + 1, 0);
  for (int i = n - 1; i >= 0; --i) {
    ans[i] = std::min((sm[i + 1] - p[i] * (n - i)) * b, ans[i + 1] + (a + b) * (p[i + 1] - p[i]));
  }
  std::cout << ans[0] << '\n';
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
