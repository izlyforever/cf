#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    std::sort(a.begin(), a.end());
    b.emplace_back(0);
    std::sort(b.begin(), b.end());
    b.emplace_back(INT_MAX);
    int ans = 0;
    for (int i = 0, l = 0, r = 0; i <= m; ++i) {
      while (r < n && a[r] < b[i + 1]) ++r;
      while (l < r && a[l] <= b[i]) ++l;
      ans = std::max(ans, r - l);
    }
    if (ans == 0) std::cout << "Impossible\n";
    else std::cout << ans << "\n";
  }
  return 0;
}