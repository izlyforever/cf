#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, p;
  std::cin >> n >> m >> p;
  std::vector<std::string> a(n);
  for (auto &x : a) std::cin >> x;
  // jiangly yyds
  auto begin = std::chrono::steady_clock::now();
  std::mt19937 rnd(begin.time_since_epoch().count());
  LL ans = 0;
  while ((std::chrono::steady_clock::now() - begin).count() < 1.5e9) {
    int x = rnd() % n;
    std::vector<int> b;
    for (int i = 0; i < m; ++i) if (a[x][i] == '1') b.emplace_back(i);
    int cnt = b.size();  // 题目要求 cnt <= p，所以不会很大
    std::vector<int> sum(1 << cnt);
    for (const auto &s : a) {
      int msk = 0;
      for (int i = 0; i < cnt; ++i) if (s[b[i]] == '1') {
        msk |= 1 << i;
      }
      ++sum[msk];
    }
    // 根据 sum 就可以计算真正的 sum[i] 了
    for (int i = 1; i < (1 << cnt); i *= 2) {
      for (int j = 0; j < (1 << cnt); j += 2 * i) {
        for (int k = 0; k < i; ++k) {
          // 注意到 (j + k) & i = 0
          sum[j + k] += sum[i + j + k];
        }
      }
    }
    int cur = 0;
    for (int i = 0; i < (1 << cnt); ++i) if (sum[i] >= (n + 1) / 2) {
      if (__builtin_popcount(i) > __builtin_popcount(cur)) cur = i;
    }
    if (__builtin_popcount(cur) > __builtin_popcountll(ans)) {
      ans = 0;
      for (int i = 0; i < cnt; ++i) if (cur >> i & 1) {
        ans |= 1LL << b[i];
      }
    }
  }
  for (int i = 0; i < m; ++i) std::cout << (ans >> i & 1);
  std::cout << '\n';
  return 0;
}