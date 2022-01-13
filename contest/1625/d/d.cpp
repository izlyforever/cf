#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, val;
  std::cin >> n >> val;
  std::vector<int> choose(n);
  std::vector<std::pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    a[i] = {x, i};
  }
  std::function<bool(int, int, int, int, int)> work = [&](int l1, int r1, int l2, int r2, int k) -> bool {
    // std::cerr << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << ' ' << k << '\n';
    if (k == 0 || l1 == r1 || l2 == r2) {
      return false;
    }
    int m1 = std::partition_point(a.begin() + l1, a.begin() + r1, [k](auto x) {
        return (x.first >> k - 1 & 1) == 0;
    }) - a.begin();
    int m2 = std::partition_point(a.begin() + l2, a.begin() + r2, [k](auto x) {
        return (x.first >> k - 1 & 1) == 0;
    }) - a.begin();
    if (val >> k - 1 & 1) {
      return work(l1, m1, m2, r2, k - 1) || work(m1, r1, l2, m2, k - 1);
    }
    if (l1 != m1 && m2 != r2) {
      choose[a[l1].second] = choose[a[m2].second] = 1;
      return true;
    }
    if (m1 != r1 && l2 != m2) {
      choose[a[m1].second] = choose[a[l2].second] = 1;
      return true;
    }
    return work(l1, m1, l2, m2, k - 1) || work(m1, r1, m2, r2, k - 1);
  };
  if (val == 0) {
    std::fill(choose.begin(), choose.end(), 1);
  } else {
    std::sort(a.begin(), a.end());
    int k = --val == 0 ? 0 : std::__lg(val) + 1;
    for (int i = 0, j; i < n; i = j) {
      j = i;
      while (j < n && a[i].first >> k == a[j].first >> k) ++j;
      int m = std::partition_point(a.begin() + i, a.begin() + j, [k](auto x) {
        return (x.first >> k - 1 & 1) == 0;
      }) - a.begin();
      if (!work(i, m, m, j, k - 1)) {
        choose[a[i].second] = 1;
      }
    }
  }
  std::vector<int> ans;
  for (int i = 0; i < n; ++i) if (choose[i]) {
    ans.emplace_back(i);
  }
  if (ans.size() > 1) {
    std::cout << ans.size() << '\n';
    for (auto x : ans) std::cout << x + 1 << ' ';
    std::cout << '\n';
  } else {
    std::cout << -1 << '\n';
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}