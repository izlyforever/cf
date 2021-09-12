#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
int solve() {
  std::string a;
  std::cin >> a;
  int n = a.size(), i = 0;
  while (i < n && a[i] == '1') ++i;
  if (i == n) return 0;
  while (i < n && a[i] == '0') ++i;
  while (i < n && a[i] == '1') ++i;
  if (i == n) return 1;
  return 2;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}