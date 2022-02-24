#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
using ULL = unsigned long long;
const int N = 1e5 + 2;
const int sqrtN = std::sqrt(N);

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
  std::map<int, std::vector<int>> mp;
  int sz = a.size();
  for (int i = 0; i < sz; ++i) {
    for (int j = 1; j <= m; ++j) {
      mp[a[i][j]].emplace_back(i);
    }
  }
  std::map<int, std::bitset<N>> bmp;
  for (auto &[x, v] : mp) {
    if (v.size() >= sqrtN) {
      std::bitset<N> tmp;
      tmp.set();
      for (auto t : v) tmp[t] = 0;
      bmp[x] = std::move(tmp);
    }
  }
  int ans = INT_MAX;
  std::bitset<N> A;
  for (int i = 0; i < sz; ++i) {
    A.set();
    for (int j = 1; j <= m; ++j) {
      auto& it = mp[a[i][j]];
      if (it.size() < sqrtN) {
        for (auto x : it) A[x] = 0;
      } else {
        A &= bmp[a[i][j]];
      }
    }
    int x = A._Find_first();
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