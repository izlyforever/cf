#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  std::multiset<int> S{INT_MAX}, Q;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i] >> b[i];
    Q.insert(a[i]);
    Q.insert(b[i]);
  }
  LL ans = 0;
  for (int i = 0; i < n; ++i) {
    Q.erase(Q.find(a[i]));
    if (*Q.rbegin() <= a[i]) {
      while (*S.begin() <= a[i]) {
        ans += a[i] - *S.begin();
        S.erase(S.begin());
      }
      S.insert(b[i]);
    } else {
      S.insert(std::min(a[i], b[i]));
      if (*Q.rbegin() <= b[i]) {
        while (*S.begin() <= b[i]) {
          ans += b[i] - *S.begin();
          S.erase(S.begin());
        }
      }
    }
    Q.erase(Q.find(b[i]));
  }
  std::cout << ans << '\n';
  return 0;
}