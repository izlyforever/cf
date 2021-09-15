#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  int r = 0;
  for (auto& x : a) {
    std::cin >> x;
    r += x;
  }
  while (m--) {
    int t, x;
    std::cin >> t >> x;
    --x;
    if (t == 1) {
      if (a[x] == 1) --r;
      else ++r;
      a[x] = 1 - a[x];
    } else {
      std::cout << int(x < r) << "\n";
    }
  }
  return 0;
}