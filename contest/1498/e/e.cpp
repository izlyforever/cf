#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n);
  int now = -1;
  for (auto& [x, id] : a) std::cin >> x, id = ++now;
  std::sort(a.begin(), a.end());
  int sm = 0, p = 0, A = 0, B = 0, ans = -1;
  for (int i = 0; i < n; ++i) {
    sm += a[i].first - i;
    if (sm == 0) {
      if (i != p) {
        int u = a[i].first - a[p].first;
        if (u > ans) {
          ans = u;
          A = a[i].second + 1;
          B = a[p].second + 1;
        }
      }
      p = i + 1;
    }
  }
  std::cout << "! " << A << ' ' << B << std::endl;
  return 0;
}
