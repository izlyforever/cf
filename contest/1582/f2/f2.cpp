#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  const int N = 5001;
  std::vector<std::vector<int>> pos(N);
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    pos[x].emplace_back(i);
  }
  const int BN = 8192;
  std::vector<int> left(BN, INT_MAX);
  left[0] = -1;
  for (int i = 0; i < N; ++i) if (!pos[i].empty()) {
    for (int j = 0; j < BN; ++j) {
      auto it = std::upper_bound(pos[i].begin(), pos[i].end(), left[j]);
      if (it != pos[i].end()) left[i ^ j] = std::min(left[i ^ j], *it);
    }
  }
  int ans = BN - std::count(left.begin(), left.end(), INT_MAX);
  std::cout << ans << '\n';
  for (int i = 0; i < BN; ++i) if (left[i] != INT_MAX) {
    std::cout << i << ' ';
  }
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