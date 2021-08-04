#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    auto mi = std::min_element(a.begin(), a.end());
    int r = 0;
    for (auto it = a.begin(); it != a.end(); ++it) if (it != mi) {
      r += (k - *it) / *mi;
    }
    print(r);
  }
  return 0;
}