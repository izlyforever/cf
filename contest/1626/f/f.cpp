#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

const int M = 998244353;
int powMod(int x, int n) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1LL * r * x % M;
    n >>= 1;   x = 1LL * x * x % M;
  }
  return r;
}
void addM(int& x, int y) {
  x += y;
  if (x >= M) x -= M;
}

void solve() {
  int n, a, x, y, k, mod;
  std::cin >> n >> a >> x >> y >> k >> mod;
  int lcmK = 1;
  for (int i = 2; i < k; ++i) {
    lcmK = std::lcm(lcmK, i);
  }
  std::vector<int> cnt(lcmK);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cur = a % lcmK;
    ++cnt[cur];
    addM(ans, a - cur);
    a = (1LL * a * x + y) % mod;
  }
  int invN = powMod(n, M - 2);
  ans = 1LL * ans * k % M * invN % M;
  for (auto &x : cnt) x = 1LL * x * invN % M;
  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < lcmK; ++j) {
      ans = (ans + 1LL * j * cnt[j]) % M;
      int tmp = cnt[j];
      cnt[j] = 1LL * tmp * (1 + M - invN) % M;
      addM(cnt[j - j % i], 1LL * tmp * invN % M);
    }
  }
  std::cout << 1LL * ans * powMod(n, k) % M << '\n';
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
