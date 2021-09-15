#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::map<int, LL> mp;
    LL ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += mp[a[i]] * (n - i);
      mp[a[i]] += i + 1;
    }
    std::cout << ans << '\n';
  }
  return 0;
}