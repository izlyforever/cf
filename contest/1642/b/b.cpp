#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++mp[x];
  }
  auto getMin = [&]() {
    for (int i = 1; i < mp.size(); ++i) {
      std::cout << mp.size() << ' ';
    }
    for (int i = mp.size(); i <= n; ++i) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  };
  auto getMax = [&]() {
    std::vector<int> cnt(n + 1);
    for (auto [_, c] : mp) ++cnt[c];
    int s = std::accumulate(cnt.begin(), cnt.end(), 0);
    for (int i = 1, ans = 0; i <= n; ++i) {
      std::cout << ans + s * i << ' ';
      ans += cnt[i] * i;
      s -= cnt[i];
    }
    std::cout << '\n';
  };
  getMin();
  // getMax();
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
