#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(n);
  bool flag = false;
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    if (++a[--u] == n) flag = true;
    if (++b[--v] == n) flag = true;
  }
  std::cout << (flag ? n - 1 : n) << '\n';
  return 0;
}
