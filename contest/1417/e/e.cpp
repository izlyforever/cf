#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int r = 0;
  LL cnt = 0;
  for (int d = 1; d < 31; ++d) {
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(),[&](int i, int j) {
      return (a[i] >> d) < (a[j] >> d) || ((a[i] >> d) == (a[j] >> d) && i < j);
    });
    LL c0 = 0, c1 = 0;
    for (int i = 0, j = 0; i < n; i = j) {
      int x0 = 0, x1 = 0;
      while (j < n && (a[p[i]] >> d) == (a[p[j]] >> d)) {
        if ((a[p[j]] >> (d - 1)) & 1) {
          ++x1;
          c0 += x0;
        } else {
          ++x0;
          c1 += x1;
        }
        ++j;
      }
    }
    if (c0 < c1) {
      cnt += c0;
      r |= (1 << d - 1);
    } else cnt += c1;
  }
  std::cout << cnt << " " << r << std::endl;
  return 0;
}