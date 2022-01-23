#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto &x : a) std::cin >> x;
  {
    int now = 0;
    std::vector<int> cnt(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      ++cnt[a[i]];
      while (cnt[now]) ++now;
      b[i] = now;
    }
  }
  std::vector<int> ans, cnt(n + 1);
  for (int i = 0, j = 0, now = 0; i < n; ++i) {
    ++cnt[a[i]];
    while (cnt[now]) ++now;
    if (now == b[j]) {
      ans.emplace_back(now);
      now = 0;
      for (int k = j; k <= i; ++k) --cnt[a[k]];
      j = i + 1;
    }
  }
  std::cout << ans.size() << '\n';
  for (auto x : ans) std::cout << x << ' ';
  std::cout << '\n';
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