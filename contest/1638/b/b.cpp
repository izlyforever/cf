#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> a[2];
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    a[x & 1].emplace_back(x);
  }
  return std::is_sorted(a[0].begin(), a[0].end()) && std::is_sorted(a[1].begin(), a[1].end());
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Yes" : "No") << '\n';
  }
  return 0;
}
