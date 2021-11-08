#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> cnt(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    ++cnt[b];
  }
  int id = 1;
  while (cnt[id]) ++id;
  for (int i = 1; i <= n; ++i) if (i != id) {
    std::cout << id << ' ' << i << '\n';
  }
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}