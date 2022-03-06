#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x :a) std::cin >> x;
    std::vector<int> sz;
    sz.push_back(1);
    for (int i = 2, now = 1, nxt = 0; i < n; ++i) {
      ++nxt;
      if (a[i] < a[i - 1]) {
        if (++now > sz.back()) {
          sz.push_back(nxt);
          now = 1;
          nxt = 0;
        }
      }
    }
    print(sz.size());
  }
  return 0;
}
