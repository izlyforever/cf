#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::map<int, std::vector<int>> mp;
  for (int i = 0; i < n; ++i) {
    mp[a[i]].emplace_back(i);
  }
  std::vector<int> ans(n);
  for (auto &[_, cnt] : mp) {
    if (cnt.size() == 1) {
      std::cout << -1 << '\n';
      return;
    }
    ans[cnt[0]] = cnt.back();
    for (int i = cnt.size() - 1; i > 0; --i) {
      ans[cnt[i]] = cnt[i - 1];
    }
  }
  for (int i = 0; i < n; ++i) {
    std::cout << ans[i] + 1 << ' ';
  }
  std::cout << '\n';

  for (int i = 0; i < n; ++i) {
    assert(ans[i] != i && a[ans[i]] >= a[i]);
  }
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
