#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;


// 根据情况换成 bool
bool solve() {
  int n, m, d;
  std::cin >> n >> m >> d;
  std::vector<std::string> a(n), b(n, std::string(m, '.'));
  for (auto &x : a) std::cin >> x;
  auto check = [&](int i, int j) -> bool {
    if (i < 0 || i >= n) return false;
    if (j < 0 || j >= m) return false;
    return a[i][j] == '*';
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '*') {
        int k = 1;
        while (check(i - k, j - k) && check(i - k, j + k)) ++k;
        if (k > d) {
          for (int t = 0; t < k; ++t) {
            b[i - t][j - t] = b[i - t][j + t] = '*';
          }
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) { return false; }
  }
  return true;
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