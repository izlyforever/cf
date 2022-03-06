#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, mul;
  std::cin >> n >> mul;
  std::multiset<LL> S;
  for (int i = 0; i < n; ++i) {
    LL x;
    std::cin >> x;
    S.insert(x);
  }
  int ans = 0;
  while (!S.empty()) {
    auto it = S.find(*S.begin() * mul);
    if (it == S.end()) {
      ++ans;
    } else {
      S.erase(it);
    }
    S.erase(S.begin());
  }
  std::cout << ans << '\n';
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
