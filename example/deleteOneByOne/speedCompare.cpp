#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
#include "../../cpplibforCP/cpplib/timer.hpp"

void solve() {
  int n = 1e6 + 2;
  std::map<int, int> a;
  for (int i = 0; i < n; ++i) {
    a[rand()] = i;
  }

  auto b = a;
  {
    Timer A;
    LL ta = 0;
    while (!a.empty()) {
      auto it = a.begin();
      ta += it->second;
      a.erase(it);
    }
    cerr(ta);
  }
  {

  }
  {
    Timer B;
    LL tb = 0;
    for (auto it = b.begin(); it != b.end(); ++it) {
      tb += it->second;
    }
    b.clear();
    cerr(tb);
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}