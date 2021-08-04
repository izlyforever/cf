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
    for (int i = 1; i < n; ++i) a[i] += a[i - 1];
    int sm = a.back(), ans;
    for (ans = n; ans >= 1; --ans) if (sm % ans == 0) {
      int mean = sm / ans, cnt = 0;
      for (int j = 0; j < n; ++j) if (a[j] % mean == 0) ++cnt;
      if (cnt == ans) break;
    }
    std::cout << n - ans << std::endl;
  }
  return 0;
}