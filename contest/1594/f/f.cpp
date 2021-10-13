#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
bool solve() {
  LL s, n, k;
  std::cin >> s >> n >> k;
  if (s == k) return true;
  LL x = n / k * 2 * k + n % k;
  return s < x;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}