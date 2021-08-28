#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::string s;
    std::cin >> s;
    auto f = [&](char x) { return x - 'A';};
    auto check = [&](int i) -> bool {
      int cnt = 0;
      for (auto x : s) {
        if (i & (1 << f(x))) ++cnt;
        else --cnt;
        if (cnt < 0) return 0;
      }
      return cnt == 0;
    };
    bool flag = false;
    for (int i = 0; i < 8; ++i) flag |= check(i);
    std::cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}