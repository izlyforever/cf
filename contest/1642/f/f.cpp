#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
using ULL = unsigned long long;
// 6 Gb is needed
constexpr int N = 1564;
using Node = std::array<ULL, N>;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a;
  a.reserve(n);
  for (int step = 0; step < n; ++step) {
    std::vector<int> am(m + 1);
    for (int i = 1; i <= m; ++i) {
      std::cin >> am[i];
    }
    std::cin >> am[0];
    std::sort(am.begin() + 1, am.end());
    if ([&]() -> bool {
          for (int i = 2; i <= m; ++i) {
            if (am[i] == am[i - 1]) return false;
          }
          return true;
        }()) {
      a.emplace_back(std::move(am));
    }
  }
  std::sort(a.begin(), a.end());
  std::map<int, Node> mp;
  int sz = a.size();
  for (int i = 0; i < sz; ++i) {
    for (int j = 1; j <= m; ++j) {
      mp[a[i][j]][i / 64] |= 1ULL << (i % 64);
    }
  }
  int ans = INT_MAX;
  for (int i = 0; i < sz; ++i) {
    auto hsh = mp[a[i][1]];
    for (int j = 2; j <= m; ++j) {
      auto& tmp = mp[a[i][j]];
      for (int t = 0; t < N; ++t) {
        hsh[t] |= tmp[t];
      }
    }
    int x = sz;
    for (int j = 0; j < N; ++j) if (hsh[j] != std::numeric_limits<ULL>::max()) {
      int k = 0;
      while (hsh[j] & (1ULL << k)) ++k;
      x = j * 64 + k;
      break;
    }
    if (x < sz) ans = std::min(ans, a[i][0] + a[x][0]);
  }
  std::cout << (ans == INT_MAX ? -1 : ans) << '\n';
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