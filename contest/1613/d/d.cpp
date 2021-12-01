#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

const int M = 998244353;
void add(int& x, int y) {
  x += y;
  if (x >= M) x -= M;
}
void solve() {
  // ma[x] 表示 mex(S) = x，且最大值为 x - 1
  // mb[x] 表示 mex(S) = x，且最大值为 x + 1
  std::map<int, int> ma{{0, 1}}, mb;
  // std::map<int, std::map<int, 
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : a) {
    std::map<int, int> maNew, mbNew;
    if (ma.count(x)) add(maNew[x + 1], ma[x]);
    if (ma.count(x + 1)) add(maNew[x + 1], ma[x + 1]);
    if (ma.count(x - 1)) add(mbNew[x - 1], ma[x - 1]);
    if (mb.count(x - 1)) add(mbNew[x - 1], mb[x - 1]);
    if (mb.count(x + 1)) add(mbNew[x + 1], mb[x + 1]);
    for (auto [x, c] : maNew) add(ma[x], c);
    for (auto [x, c] : mbNew) add(mb[x], c);
  }
  int ans = M - 1;
  for (auto [x, c] : ma) add(ans, c);
  for (auto [x, c] : mb) add(ans, c);
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}