#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  LL r = 0;
  for (int i = 0; i < n; ++i) {
    r += (a[i] - i);
    if (r < 0) return 0;
  }
  return 1;
}
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << "\n";
  }
  return 0;
}
