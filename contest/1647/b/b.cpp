#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int f(char x) {
  return x - '0';
}

bool solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n);
  for (auto &x : a) std::cin >> x;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      int tmp = f(a[i][j]) + f(a[i - 1][j]) + f(a[i - 1][j - 1]) + f(a[i][j - 1]);
      if (tmp == 3) return false;
    }
  }
  return true;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
