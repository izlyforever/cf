#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::vector<std::vector<int>> s(n);
  for (int i = 0; i < n; ++i) s[--a[i]].emplace_back(i);
  // 随机化做法，结果正确的概率为 1 / 2^CNT;
  const int CNT = 50;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    --l; --r;
    std::map<int, int> mp;
    int ans = 1, len = r - l + 1;
    for (int i = 0; i < CNT; ++i) {
      int j = rnd() % len, x = a[l + j];
      if (++mp[x + l] == 1) {
        auto il = std::lower_bound(s[x].begin(), s[x].end(), l);
        auto ir = std::upper_bound(s[x].begin(), s[x].end(), r);
        int t = std::distance(il, ir);
        if (t > len - t) {
          ans = t + t - len;
          break;
        }
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}