#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    int mn = std::min_element(a.begin(), a.end()) - a.begin();
    int mx = std::max_element(a.begin(), a.end()) - a.begin();
    if (mn > mx) std::swap(mn, mx);
    std::cout << std::min({mn + 1 + n - mx, mx + 1, n - mn}) << '\n';
  }
  return 0;
}