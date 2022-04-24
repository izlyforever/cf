#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), cnt(n), ans(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : a) ++cnt[--x];
  std::vector<std::pair<int, int>> b;
  for (int i = 0; i < n; ++i) if (cnt[i] > 0) {
    b.emplace_back(cnt[i], i);
  }
  std::sort(b.begin(), b.end());
  int nb = b.size();
  std::map<int, int> mp;
  for (int i = nb - 1; i > 0; --i) {
    b[i].first -= b[i - 1].first;
    mp[b[i - 1].second] = b[i].second;
  }
  int mx = b.back().second;
  for (int i = 0, j = 0; i < n; ++i) {
    if (a[i] != mx) {
      ans[i] = mp[a[i]];
    } else {
      while (j < nb && b[j].first == 0) ++j;
      ans[i] = b[j].second;
      --b[j].first;
    }
  }
  for (int i = 0; i < n; ++i) std::cout << ans[i] + 1 << " \n"[i == n - 1];
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
