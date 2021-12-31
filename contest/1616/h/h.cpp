#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int M = 998244353;
void add(int& x, int y) {
  x += y;
  if (x >= M) x -= M;
}

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> p2(n + 1);
  p2[0] = 1;
  for (int i = 1; i <= n; ++i) add(p2[i], p2[i - 1] * 2);
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::sort(a.begin(), a.end());

  std::function<int(int, int, int, int, int)> work = [&](int l1, int r1, int l2, int r2, int k) -> int {
    if (k == 0 || l1 == r1 || l2 == r2) {
      return p2[r1 - l1 + r2 - l2];
    }
    int m1 = std::partition_point(a.begin() + l1, a.begin() + r1, [k](int x) {
        return (x >> k - 1 & 1) == 0;
    }) - a.begin();
    int m2 = std::partition_point(a.begin() + l2, a.begin() + r2, [k](int x) {
        return (x >> k - 1 & 1) == 0;
    }) - a.begin();
    if (x >> k - 1 & 1) {
      return 1LL * work(l1, m1, m2, r2, k - 1) * work(m1, r1, l2, m2, k - 1) % M;
    }
    int ans = M - 1;
    add(ans, work(l1, m1, l2, m2, k - 1));
    add(ans, work(m1, r1, m2, r2, k - 1));
    ans = (ans + 1LL * (p2[m1 - l1] - 1) * (p2[r1 - m1] - 1)) % M;
    ans = (ans + 1LL * (p2[m2 - l2] - 1) * (p2[r2 - m2] - 1)) % M;
    return ans;
  };
  int ans = 0;
  int k = x == 0 ? 0 : std::__lg(x) + 1;
  for (int i = 0, j; i < n; i = j) {
    j = i;
    while (j < n && a[i] >> k == a[j] >> k) ++j;
    int m = std::partition_point(a.begin() + i, a.begin() + j, [k](int x) {
      return (x >> k - 1 & 1) == 0;
    }) - a.begin();
    ans += work(i, m, m, j, k - 1) - 1;
  }
  std::cout << ans << '\n';
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