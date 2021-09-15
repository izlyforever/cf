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
    std::vector<std::string> s(n);
    for (auto& x : s) std::cin >> x;
    int a[2][3] = {};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (s[i][j] == 'O') ++a[0][(i + j) % 3];
        if (s[i][j] == 'X') ++a[1][(i + j) % 3];
      }
    }
    int x = 0;
    for (int i = 1; i < 3; ++i) {
      if (a[0][i] + a[1][(i + 1) % 3] < a[0][x] + a[1][(x + 1) % 3]) {
        x = i;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (s[i][j] == 'O' && (i + j) % 3 == x) {
          s[i][j] = 'X';
        }
        if (s[i][j] == 'X' && (i + j + 2) % 3 == x) {
          s[i][j] = 'O';
        }
      }
    }
    for (auto& x : s) std::cout << x << std::endl;
  }
  return 0;
}