#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<std::pair<int, double>> b(m);
    for (auto& [x, y] : b) std::cin >> x >> y;
    std::cout.precision(6);
    int now = n - 1;
    while (now >= 0 && a[now] == now + 1) --now;
    double ans = 1;
    if (now != -1) {
      for (auto [x, y] : b) if (x > now) {
        ans *= (1 - y);
      }
      ans = 1 - ans;
    }
    std::cout << std::fixed << ans << std::endl;
  }
  return 0;
}