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
    for (auto &x : s) std::cin >> x;
    std::vector<std::pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) if (s[i][j] == '*') {
        a.emplace_back(i, j);
      }
    }
    if (a[0].first != a[1].first && a[0].second != a[1].second) {
      s[a[0].first][a[1].second] = s[a[1].first][a[0].second] = '*';
    } else if (a[0].first == a[1].first) {
      if (a[0].first == 0) {
        s[1][a[0].second] = s[1][a[1].second] = '*';
      } else {
        s[0][a[0].second] = s[0][a[1].second] = '*';
      }
    } else {
      if (a[0].second == 0) {
        s[a[0].first][1] = s[a[1].first][1] = '*';
      } else {
        s[a[0].first][0] = s[a[1].first][0] = '*';
      }
    }
    for (auto &x : s) std::cout << x << '\n';
  }
  return 0;
}