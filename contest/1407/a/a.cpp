#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    int cnt = 0;
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      if (x) ++cnt;
    }
    int t = 0;
    if (cnt > n / 2) {
      t = 1;
      if (cnt % 2) --cnt;
    } else cnt = n - cnt;
    std::cout << cnt << std::endl;
    for (int i = 0; i < cnt; ++i) std::cout << t << " \n"[i == cnt];
  }
  return 0;
}