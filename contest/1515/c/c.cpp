#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, m, x;
    std::cin >> n >> m >> x;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      a[i] = {x, i};
    }
    std::sort(a.begin(), a.end(), std::greater<>());
    std::set<std::pair<int, int>> S;
    for (int i = 1; i <= m; ++i) S.insert({0, i});
    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      auto [val, id] = *S.begin();
      S.erase(S.begin());
      S.insert({val + a[i].first, id});
      ans[a[i].second] = id;
    }
    std::cout << "YES\n";
    for (auto& x : ans) std::cout << x << ' ';
    std::cout << '\n';
  }
  return 0;
}