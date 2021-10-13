#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  char a;
  std::string s;
  std::cin >> n >> a >> s;
  auto check = [&](int x) -> bool {
    for (int i = x - 1; i < n; i += x) {
      if (s[i] != a) return false;
    }
    return true;
  };
  if (check(1)) {
    std::cout << 0 << '\n';
    return;
  }
  for (int i = n; i > 1; --i) {
    if (check(i)) {
      std::cout << 1 << '\n';
      std::cout << i << '\n';
      return;
    }
  }
  std::cout << 2 << '\n';
  std::cout << n - 1 << ' ' << n << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}