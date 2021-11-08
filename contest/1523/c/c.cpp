#include <bits/stdc++.h>
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
    std::vector<int> Q{1};
    std::cout << 1 << '\n';
    for (int i = 1; i < n; ++i) {
      if (a[i] == 1 || Q.empty()) {
        Q.emplace_back(a[i]);
      } else {
        // 必然可行
        while (Q.back() != a[i] - 1) Q.pop_back();
        ++Q.back();
      }
      std::cout << Q[0];
      for (int i = 1; i < Q.size(); ++i) std::cout << '.' << Q[i];
      std::cout << '\n';
    }
  }
  return 0;
}