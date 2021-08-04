#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q, k;
  std::cin >> n >> q >> k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    --l; --r;
    std::cout << 1 + k + a[r] - a[l] - 2 * (r - l + 1) << "\n";
  }
  return 0;
}