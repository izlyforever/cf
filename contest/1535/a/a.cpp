#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::vector<int> a(4), p(4);
    for (auto& x : a) std::cin >> x;
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    std::cout << ((p[0] > 1) ^ (p[1] > 1) ? "YES" : "NO") << '\n';
  }
  return 0;
}