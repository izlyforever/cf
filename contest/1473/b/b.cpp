#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::string a, b;
    std::cin >> a >> b;
    auto f = [](std::string s) -> std::pair<std::string, int> {
      auto g = [&](int n) {
        for (int i = 0; i < s.size(); ++i) {
          if (s[i] != s[i % n]) return false;
        }
        return true;
      };
      for (int i = 1; i <= s.size(); ++i) if (s.size() % i == 0 && g(i)) {
        return {s.substr(0, i), s.size() / i};
      }
      return {s, 1};
    };
    auto [fa, na] = f(a);
    auto [fb, nb] = f(b);
    if (fa != fb) {
      std::cout << "-1\n";
    } else {
      int nc = std::lcm(na, nb);
      for (int i = 0; i < nc; ++i) std::cout << fa;
      std::cout << "\n";
    }
  }
  return 0;
}