#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (auto& x : a) {
      std::cin >> x;
      --x;
    }
    std::sort(a.rbegin(), a.rend());
    std::vector<int> c(m);
    for (auto& x : c) std::cin >> x;
    LL r = 0;
    int now = 0;
    for (int i = 0; i < n; ++i) {
      if (now < m && now <= a[i]) {
        r += c[now];
        ++now;
      } else {
        r += c[a[i]];
      }
    }
    std::cout << r << std::endl;
  }
  return 0;
}