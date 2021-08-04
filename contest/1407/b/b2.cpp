#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    int a[n];
    bool v[n] = {};
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int id = std::max_element(a, a + n) - a;
    std::vector<int> ans;
    ans.push_back(a[id]);
    v[id] = 1;
    int now = a[id];
    while (ans.size() != n) {
      int mx = 0, mi = 1e9 + 2;
      for (int i = 0; i < n; ++i) if (!v[i]) {
        mx = std::max(mx, std::__gcd(now, a[i]));
        mi = std::max(mi, std::__gcd(now, a[i]));
      }
      if (mx == mi) break;
      for (int i = 0; i < n; ++i) if (!v[i]) {
        if(mx == std::__gcd(now, a[i])) {
          ans.push_back(a[i]);
          v[i] = 1;
        }
      }
      now = mx;
    }
    for (auto x : ans) std::cout << x << " ";
    for (int i = 0; i < n; ++i) if (!v[i]) std::cout << a[i] << " ";
    std::cout << std::endl;
  }
  return 0;
}