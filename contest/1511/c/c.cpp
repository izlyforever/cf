#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  std::cin >> n >> q;
  std::list<int> a;
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    a.emplace_back(x);
  }
  while (q--) {
    int c;
    std::cin >> c;
    auto it = std::find(a.begin(), a.end(), c);
    if (it != a.end()) {
      std::cout << int(std::distance(a.begin(), it) + 1) << ' ';
      a.erase(it);
      a.emplace_front(c);
    }
  }
  std::cout << '\n';
  return 0;
}
