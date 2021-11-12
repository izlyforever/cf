#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    auto f = [](std::vector<int> a, int M) {
      std::vector<int> b{1};
      for (auto x : a) b.emplace_back(LL(b.back()) * x % M);
      std::map<int, int> mp;
      int len = INT_MAX;
      for (int j = a.size(); j > 0; --j) {
        mp[b[j]] = j;
        if (mp[b[j - 1]]) len = std::min(len, mp[b[j - 1]] - j + 1);
      }
      return len;
    };
    int now = 0, r = INT_MAX;
    while (now < n) {
      while (now < n && std::__gcd(a[now], n) != 1) ++now;
      int tmp = now;
      while (now < n && std::__gcd(a[now], n) == 1) ++now;
      if (tmp < now) r = std::min(r, f(std::vector<int>(a.begin() + tmp, a.begin() + now), n));
    }
    std::cout << (r == INT_MAX ? 0 : r) << std::endl;
  }
  return 0;
}