#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  const LL MAX = 1LL << 31;
  std::set<int> a;
  for (int i = 1; i <= 9; ++i) {
    LL now = i;
    while (now < MAX) {
      a.emplace(now);
      now = 10 * now + i;
    }
  }
  auto b = a;
  for (int i = 1; i <= 9; ++i) {
    for (int j = 0; j < i; ++j) {
      std::function<void(LL)> dfs = [&](LL now) {
        if (now >= MAX) return;
        b.emplace(now);
        dfs(now * 10 + i);
        dfs(now * 10 + j);
      };
      dfs(i);
      if (j > 0) dfs(j);
    }
  }
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    if (k == 1) {
      std::cout << *a.lower_bound(n) << '\n';
    } else {
      std::cout << *b.lower_bound(n) << '\n';
    }
  }
  return 0;
}