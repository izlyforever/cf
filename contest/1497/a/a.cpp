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
    std::multiset<int> S;
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      S.insert(x);
    }
    int now = 0;
    while (S.count(now)) {
      std::cout << now << ' ';
      S.erase(S.find(now));
      ++now;
    }
    for (auto x : S) std::cout << x << ' ';
    std::cout << '\n';
  }
  return 0;
}