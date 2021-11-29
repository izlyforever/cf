#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

std::vector<int> solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n), ans(n);
  std::vector<std::vector<int>> cnt(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    cnt[--a[i]].emplace_back(i);
  }
  for (int i = 0; i < n; ++i) if (cnt[i].size() >= k) {
    for (int j = 0; j < k; ++j) ans[cnt[i][j]] = j + 1;
  }
  int x = 0;
  for (int i = 0; i < n; ++i) if (cnt[i].size() < k) x += cnt[i].size();
  x /= k;
  if (x == 0) return ans;
  for (int i = 0, now = 1; i < n; ++i) if (cnt[i].size() < k) {
    for (auto t : cnt[i]) {
      ans[t] = now++;
      if (now > k) {
        now = 1;
        if (--x == 0) return ans;
      }
    }
  }
  return ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    for (auto x : solve()) std::cout << x << ' ';
    std::cout << '\n';
  }
  return 0;
}