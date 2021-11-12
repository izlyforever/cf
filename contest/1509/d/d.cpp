#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

std::string solve() {
  int n;
  std::cin >> n;
  std::string a[3];
  for (int i = 0; i < 3; ++i) std::cin >> a[i];
  for (char c : {'0', '1'}) {
    for (int i = 0; i < 3; ++i) if (std::count(a[i].begin(), a[i].end(), c) >= n) {
      for (int j = i + 1; j < 3; ++j) if (std::count(a[j].begin(), a[j].end(), c) >= n) {
        std::string s;
        int ni = 0, nj = 0;
        while (ni < 2 * n && nj < 2 * n) {
          if (a[i][ni] == a[j][nj]) {
            s += a[i][ni];
            ++ni; ++nj;
          } else {
            s += (a[i][ni] == c ? a[j][nj++] : a[i][ni++]);
          }
        }
        for (int k = ni; k < 2 * n; ++k) s += a[i][k];
        for (int k = nj; k < 2 * n; ++k) s += a[j][k];
        return s;
      }
    }
  }
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}