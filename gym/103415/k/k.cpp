#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
constexpr int M = 998244353;

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
void sub(int& x, int y) {
  x -= y;
  if (x < 0) x += M;
}
std::vector<int> spf(int N) {
  std::vector<int> sp(N), p{0, 2};
  for (int i = 2; i < N; i += 2) sp[i] = 2;
  for (int i = 1; i < N; i += 2) sp[i] = i;
  for (int i = 3; i < N; i += 2) {
    if (sp[i] == i) p.emplace_back(i);
    for (int j = 2, np = (int)p.size(); j < np && p[j] <= sp[i] && i * p[j] < N; ++j) {
      sp[i * p[j]] = p[j]; // Note that sp[x] is assigned only once foreach x
    }
  }
  return sp;
}

int solve(int n, int m, int lcmMin, int gcdMax) {
  auto sp = spf(m + 1);                     // O(m)
  std::vector<std::vector<int>> pre(m + 1); // O(m log m)
  for (int i = 2; i <= m; ++i) if (sp[i] == i) { 
    int now = 0, pi = 1;
    while (1) {
      now += pi;
      pre[i].emplace_back(now);
      if (1LL * pi * i > m) break;
      pi *= i;
    }
  }
  std::vector<int> pn(2 * m); // O(m \log n)
  for (int i = 1; i < 2 * m; ++i) pn[i] = powMod(i, n);
  std::vector<int> e(m + 1, 1); // O(m log m)
  for (int i = 2; i <= m; ++i) {
    int x = i, p = sp[i], id = 0;
    while (x % p == 0) {
      ++id;
      x /= p;
    }
    if (x == 1) {
      auto& gp = pre[p];
      e[i] = pn[gp[id]];
      sub(e[i], pn[gp[id - 1]]);
      sub(e[i], pn[gp[id] - 1]);
      if (id > 1) add(e[i], pn[gp[id - 1] - 1]);
    } else {
      e[i] = 1LL * e[x] * e[i / x] % M;
    }
  }
  int ans = 0;
  for (int d = 1; d <= gcdMax; ++d) {
    for (int dl = m / d, l = dl * d; l >= lcmMin; l -= d, --dl) {
      ans = (ans + 1LL * pn[d] * e[dl]) % M;
    }
  }
  return ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    int n, m, p, q;
    std::cin >> n >> m >> p >> q;
    std::cout << solve(n, m, p, q) << '\n';
  }
  return 0;
}