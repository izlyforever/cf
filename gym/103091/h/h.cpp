#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::set<int> S;
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    S.insert(x);
  }
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::sort(a.begin(), a.end(), std::greater<>());
  int ans = 0;
  for (auto x : a) {
    auto it = S.lower_bound(x);
    if (it != S.end()) {
      S.erase(it);
      ++ans;
    }
  }
  std::cout << ans << '\n';
  return 0;
}
