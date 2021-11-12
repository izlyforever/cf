#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> p(n);
  for (auto& x : p) std::cin >> x;
  std::vector<std::vector<int>> r(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    int j = 0, now = 0;
    while (i + j < n) {
      while (p[now] <= i) ++now;
      r[i + j][j] = p[now];
      ++j;
      ++now;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      std::cout << r[i][j] << " \n"[j == i];
    }
  }
  return 0;
}