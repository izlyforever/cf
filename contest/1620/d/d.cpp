#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int cnt[3]{};
  for (auto x : a) ++cnt[x % 3];
  int mx = *std::max_element(a.begin(), a.end());
  int ans = mx / 3;
  if (mx % 3 == 0) {
    ans += (cnt[0] != n);
  } else if (mx % 3 == 1) {
    ++ans;
    if (cnt[2]) {
      for (int i = 0; i < n; ++i) if (a[i] == mx - 1 || a[i] == 1) {
        ++ans;
        break;
      }
    }
  } else {
    ++ans;
    ans += (cnt[1] != 0);
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