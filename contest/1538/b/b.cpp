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
    int sm = std::accumulate(a.begin(), a.end(), 0);
    if (sm % n) {
      std::cout << "-1\n";
    } else {
      sm /= n;
      int ans = 0;
      for (int i = 0; i < n; ++i) if (a[i] > sm) ++ans;
      std::cout << ans << '\n';
    }
  }
  return 0;
}