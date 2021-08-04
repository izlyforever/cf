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
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    std::sort(a.begin(), a.end());
    LL r = 0;
    for (int i = 0; i + 3 <= n; ++i) {
      int it = std::upper_bound(a.begin(), a.end(), a[i] + 2) - a.begin();
      if (it - i >= 2) r += LL(it - i - 1) * (it - i - 2) / 2;
    }
    std::cout << r << std::endl;
  }
  return 0;
}