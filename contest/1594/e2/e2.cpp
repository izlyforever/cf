#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;
const int M = 1e9 + 7;

int powMod(int x, int n) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1LL * r * x % M;
    n >>= 1;   x = 1LL * x * x % M;
  }
  return r;
}

void add(int& x, int y) {
  x += y;
  if (x >= M) x -= M;
}

void solve() {
  std::map<char, int> MP{{'w', 0}, {'y', 0}, {'g', 1}, {'b', 1}, {'r', 2}, {'o', 2}};
  int k, n;
  std::cin >> k >> n;
  std::map<LL, int> mp;
  for (int i = 0; i < n; ++i) {
    LL x;
    std::string s;
    std::cin >> x >> s;
    mp[x] = MP[s[0]];
    x /= 2;
    while (x) {
      if (mp.count(x)) break;
      mp[x] = -1;
      x >>= 1;
    }
  }
  int times = powMod(2, ((1LL << k) - 1 - n) % (M - 1));
  std::vector<int> p2(k + 1);
  for (int i = 1; i <= k; ++i) p2[i] = powMod(2, ((1LL << i) - 2) % (M - 1));
  std::map<LL, int> ans[3];
  auto f = [&](LL x, int c, int dep) {
    if (mp.count(x)) return ans[c][x];
    return p2[k - dep];
  };
  for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
    auto [x, c] = *it;
    int dep = std::__lg(x);
    if (c != -1) {
      if (dep == k - 1) ans[c][x] = 1;
      else {
        int ansl = 0, ansr = 0;
        for (int i = 0; i < 3; ++i) if (i != c) ansl = (ansl + 1LL * f(x << 1, i, dep + 1)) % M;
        for (int i = 0; i < 3; ++i) if (i != c) ansr = (ansr + 1LL * f(x << 1 | 1, i, dep + 1)) % M;
        ans[c][x] = 1LL * ansl * ansr % M;
      }
    } else {
      for (int c = 0; c < 3; ++c) {
        if (dep == k - 1) ans[c][x] = 1;
        else {
          int ansl = 0, ansr = 0;
          for (int i = 0; i < 3; ++i) if (i != c) ansl = (ansl + 1LL * f(x << 1, i, dep + 1)) % M;
          for (int i = 0; i < 3; ++i) if (i != c) ansr = (ansr + 1LL * f(x << 1 | 1, i, dep + 1)) % M;
          ans[c][x] = 1LL * ansl * ansr % M;
        }
      }
    }
  }
  int ret = 0;
  for (int i = 0; i < 3; ++i) add(ret, ans[i][1]);
  std::cout << 1LL * ret * times % M << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}