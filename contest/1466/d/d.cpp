#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> w(n);
    LL r = 0;
    for (auto& x : w) {
      std::cin >> x;
      r += x;
    }
    std::vector<int> e, d(n);
    for (int i = 1, u, v; i < n; ++i) {
      std::cin >> u >> v;
      --u;
      --v;
      ++d[u];
      ++d[v];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < d[i]; ++j) e.emplace_back(w[i]);
    }
    // watch(e.size());
    std::sort(e.rbegin(), e.rend());
    std::cout << r << " ";
    for (int i = 0; i + 2 < n; ++i) {
      r += e[i];
      std::cout << r << " ";
    }
    std::cout << "\n";
  }
  return 0;
}