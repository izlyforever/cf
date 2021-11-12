#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

const int M = 998244353;
int f(const std::vector<int>& l, std::vector<int> r, int m) {
  int n = l.size();
  for (int i = 0; i < n; ++i) {
    m -= l[i];
    r[i] -= l[i];
    if (r[i] < 0) return 0;
  }
  if (m < 0) return 0;
  std::vector<int> ans(m + 1);
  ans[0] = 1;
  for (auto x : r) {
    for (int j = 1; j <= m; ++j) {
      ans[j] += ans[j - 1];
      if (ans[j] >= M) ans[j] -= M;
    }
    for (int j = m; j > x; --j) {
      ans[j] -= ans[j - x - 1];
      if (ans[j] < 0) ans[j] += M;
    }
  }
  return std::accumulate(ans.begin(), ans.end(), 0LL) % M;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> l[i] >> r[i];
  }
  std::vector<int> mu(m + 1);
  mu[1] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = i * 2; j <= m; j += i) {
      mu[j] -= mu[i];
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; ++i) if (mu[i]) {
    auto li = l, ri = r;
    for (auto& x : li) x = (x + i - 1) / i;
    for (auto& x : ri) x /= i;
    if (mu[i] == 1) {
      ans += f(li, ri, m / i);
      if (ans >= M) ans -= M;
    } else {
      ans -= f(li, ri, m / i);
      if (ans < 0) ans += M;
    }
  }
  std::cout << ans << '\n';
  return 0;
}