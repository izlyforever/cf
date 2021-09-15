#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    int mi = std::min_element(a.begin(), a.end()) - a.begin();
    std::cout << n - 1 << '\n';
    for (int i = mi - 1, j = a[mi] + 1; i >= 0; --i, ++j) {
      std::cout << i + 1 << ' ' << mi + 1 << ' ' << j << ' ' << a[mi] << '\n';
    }
    for (int i = mi + 1, j = a[mi] + 1; i < n; ++i, ++j) {
      std::cout << i + 1 << ' ' << mi + 1 << ' ' << j << ' ' << a[mi] << '\n';
    }
  }
  return 0;
}