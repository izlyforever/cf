#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (auto &x : a) {
    std::cin >> x;
    --x;
  }
  std::vector<std::array<int, 3>> query(q);
  std::vector<int> ans(q);
  for (int i = 0; i < q; ++i) {
    int idx, k;
    std::cin >> idx >> k;
    --idx;
    query[i] = {k, idx, i};
  }
  std::sort(query.begin(), query.end());

  std::vector<int> cnt(n), b;

  int ni = 1, mxi = 0;
  for (auto [k, idx, i] : query) {
    while (ni <= k && a[mxi] != n - 1) {
      if (a[ni] > a[mxi]) {
        b.emplace_back(a[mxi]);
        mxi = ni;
      } else {
        b.emplace_back(a[ni]);
      }
      ++cnt[mxi];
      ++ni;
    }
    ans[i] = cnt[idx];
    if (a[mxi] == n - 1 && idx == mxi) {
      ans[i] += k - ni + 1;
    }
  }
  for (auto x : ans) std::cout << x << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in1.txt", "r", stdin);
#endif // ONLINE_JUDGE
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
