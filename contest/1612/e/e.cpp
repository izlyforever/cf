#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> m(n), k(n);
  for (int i = 0; i < n; ++i) std::cin >> m[i] >> k[i];
  int M = *std::max_element(m.begin(), m.end());
  int K = *std::max_element(k.begin(), k.end());
  std::vector<std::vector<int>> id(M + 1);
  for (int i = 0; i < n; ++i) id[m[i]].emplace_back(i);
  auto cmp = [](std::pair<int, int> x, std::pair<int, int> y) {
    return 1LL * x.first * y.second < 1LL * x.second * y.first;
  };
  std::pair<int, int> ans = {0, 1};
  std::vector<int> a;
  for (int i = 1; i <= K; ++i) {
    std::set<std::pair<int, int>> S;
    for (int j = 0; j <= M; ++j) if (!id[j].empty()) {
      int s = 0;
      for (auto x : id[j]) s += std::min(i, k[x]);
      S.emplace(-s, j);
    }
    std::pair<int, int> cur = {0, i};
    std::vector<int> b;
    for (int j = 0; j < i && !S.empty(); ++j) {
      cur.first -= S.begin()->first;
      b.emplace_back(S.begin()->second);
      S.erase(S.begin());
    }
    if (cmp(ans, cur)) {
      ans = cur;
      std::swap(a, b);
    }
  }
  std::cout << a.size() << '\n';
  for (auto &x : a) std::cout << x << ' ';
  std::cout << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}