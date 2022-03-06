#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> ans;
  int r = 1;
  for (int i = 1; i < n; ++i) if (std::gcd(i, n) == 1) {
    ans.emplace_back(i);
    r = LL(r) * i % n;
  }
  if (r != 1) ans.erase(std::find(ans.begin(), ans.end(), r));
  std::cout << ans.size() << '\n';
  for (auto x : ans) std::cout << x << ' ';
  std::cout << '\n';
  return 0;
}
