#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;
#include "../../cpplibforCP/cpplib/timer.hpp"

void solve() {
  int n = 1e6 + 2;
  std::map<int, int> a;
  for (int i = 0; i < n; ++i) {
    a[rand()] = i;
  }

  auto b = a;
  Timer A;
  LL ta = 0;
  while (!a.empty()) {
    auto it = a.begin();
    ta += it->second;
    a.erase(it);
  }
  A.show();

  Timer B;
  LL tb = 0;
  for (auto it = b.begin(); it != b.end(); ++it) {
    tb += it->second;
  }
  b.clear();
  B.show();
  std::cout << ta << ' ' << tb << '\n';

}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}