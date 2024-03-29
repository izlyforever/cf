#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::map<std::pair<int, int>, int> mp;
    int d = 0, k = 0;
    for (auto c : s) {
      if (c == 'D') ++d;
      else ++k;
      int dk = std::gcd(d, k);
      std::cout << ++mp[{d / dk, k / dk}] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
