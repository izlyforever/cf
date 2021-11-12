#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::string a, b;
  std::cin >> a >> b;
  std::vector<int> c(m), d(m);
  for (int i = 0, j = 0; i < m; ++i) {
    while (a[j] != b[i]) ++j;
    c[i] = j++;
  }
  for (int i = m - 1, j = n - 1; i >= 0; --i) {
    while (a[j] != b[i]) --j;
    d[i] = j--;
  }
  int r = 1;
  for (int i = 0; i + 1 < m; ++i) {
    r = std::max(r, d[i + 1] - c[i]);
  }
  std::cout << r << "\n";
  return 0;
}