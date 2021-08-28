#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n), b(n);
    for (auto &x : a) std::cin >> x;
    for (auto &x : b) std::cin >> x;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        a[i][j] = (a[i][j] != b[i][j] ? '1' : '0');
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        a[i][j] = (a[i][j] != a[0][j] ? '1' : '0');
      }
    }
    bool flag = true;
    std::string s0(n, '0'), s1(n, '1');
    for (int i = 1; i < n; ++i) {
      if (a[i] != s0 && a[i] != s1) {
        flag = false;
        break;
      }
    }
    std::cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}