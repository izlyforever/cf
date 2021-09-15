#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
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
    int mn = *std::min_element(a.begin(), a.end());
    if (mn < 0) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      std::cout << "101\n";
      for (int i = 0; i < 101; ++i) std::cout << i << ' ';
      std::cout << '\n';
    }
  }
  return 0;
}