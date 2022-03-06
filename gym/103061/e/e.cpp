#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  int ans = 0;
  for (int i = n - 1; ~i; --i) {
    ans = abs(a[i] - ans);
  }
  std::cout << ans << '\n';
  return 0;
}
