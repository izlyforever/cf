#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    int s = std::accumulate(a.begin(), a.end(), 0);
    std::cout << s / n << '.';
    s %= n;
    for (int i = 0; i < k; ++i) {
      s *= 10;
      std::cout << s / n;
      s %= n;
    }
    std::cout << '\n';
  }
  return 0;
}