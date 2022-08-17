#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
// calculate

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
    query[i] = {k, --idx, i};
  }
  std::sort(query.begin(), query.end());

  std::vector<int> cnt(n), b;

  int ni = 1, mxi = 0;
  for (auto [k, idx, i] : query) {
    while (ni <= k && a[mxi] != n - 1) {
      ++cnt[mxi];
      ++cnt[ni];
      if (a[ni] > a[mxi]) {
        b.emplace_back(a[mxi]);
        mxi = ni;
      } else {
        b.emplace_back(a[ni]);
      }
      ++ni;
    }
    if (a[mxi] != n - 1) {
      ans[i] = cnt[idx];
      continue;
    }
    if ((int)b.size() < n) {
      std::vector<int> c{n - 1}, p(n);
      c.insert(c.end(), a.begin() + ni, a.end());
      c.insert(c.end(), b.begin(), b.end());
      assert((int)c.size() == n);
      for (int j = 0; j < n; ++j) {
        p[c[j]] = j;
      }
      for (int j = 0; j < n; ++j) {
        c[j] = p[a[j]];
      }
      std::swap(b, c);
    }
    idx = b[idx];
    k -= (ni - 1);
    ans[i] = cnt[idx];
    if (idx == 0) {
      ans[i] += k;
    } else if (k >= idx) {
      ans[i] += 1 + (k - idx) / (n - 1);
    }
  }
  for (auto x : ans) std::cout << x << '\n';
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
