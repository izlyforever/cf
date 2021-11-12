#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

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
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}