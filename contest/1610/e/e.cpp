#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int ans = 0;
  for (int i = 0; i < n; ++i) if (i == 0 || a[i] != a[i - 1]) {
    int j = i;
    while (j < n && a[j] == a[i]) ++j;
    std::vector<int> cur(j - i, a[i]);
    if (j < n) cur.emplace_back(a[j++]);
    while (j < n) {
      j = std::lower_bound(a.begin() + j, a.end(), cur.back() * 2 - cur[0]) - a.begin();
      if (j < n) cur.emplace_back(a[j++]);
    }
    ans = std::max(ans, (int)cur.size());
  }
  return n - ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}