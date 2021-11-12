#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    int cnt[101] = {};
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      ++cnt[x];
    }
    int num = 0;
    for (int i = 0; i < 101; ++i) if (cnt[i]) ++num;
    if (k == 1) {
      if (num == 1) print(1);
      else print(-1);
    } else if (num <= k) {
      print(1);
    } else print((num - 2) / (k - 1) + 1);
  }
  return 0;
}