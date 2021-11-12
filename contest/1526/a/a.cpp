#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n), b(2 * n);
    for (auto& x : a) std::cin >> x;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) b[2 * i] = a[i];
    for (int i = 0; i < n; ++i) b[2 * i + 1] = a[i + n];
    for (auto x : b) std::cout << x << ' ';
    std::cout << '\n';
  }
  return 0;
}