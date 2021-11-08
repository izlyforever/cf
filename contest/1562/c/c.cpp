#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int i = 0;
  while (i < n && s[i] != '0') ++i;
  int n2 = n / 2;
  if (i != n) {
    if (i < n2) {
      std::cout << i + 1 << ' ' << n << ' '<< i + 2  << ' ' << n << '\n';
    } else {
      std::cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << '\n';
    }
  } else {
    std::cout << 1 << ' ' << n2 << ' ' << n2 + 1 << ' ' << 2 * n2 << '\n';
  }
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