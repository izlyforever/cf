#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> nxt(n, n), w(n);
  for (int i = 0, u, v; i < m; ++i) {
    std::cin >> u >> v;
    --u; --v;
    nxt[u] = v;
    w[v] = -1;
  }
  std::set<int> S;
  for (int i = 0; i < n; ++i) if (w[i] == 0) S.insert(i);
  int last = -1, cur = 1;
  while (!S.empty()) {
    auto it = S.lower_bound(last);
    if (it == S.end()) {
      ++cur;
      it = S.begin();
    }
    int i = *it;
    S.erase(it);
    while (i != n) {
      w[i] = cur;
      last = i;
      if (i > nxt[i]) ++cur;
      i = nxt[i];
    }
  }
  for (auto x : w) std::cout << x << ' ';
  std::cout << '\n';
  return 0;
}