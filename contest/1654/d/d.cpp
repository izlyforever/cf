#include <bits/stdc++.h>
#include <iostream>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int N = 2e5 + 2;
const int M = 998244353;

int powMod(int x, int n = M - 2) {
  int r = 1;
  while (n) {
    if (n & 1) r = 1LL * r * x % M;
    n >>= 1;   x = 1LL * x * x % M;
  }
  return r;
}

std::vector<int> sp(N);
void spfS() {
  std::iota(sp.begin(), sp.end(), 0);
  for(int i = 2; i * i < N; ++i) if(sp[i] == i) {
    for(int j = i * i; j < N; j += i) if(sp[j] == j) {
      sp[j] = i;
    }
  }
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::vector<std::array<int, 3>>> adj(n);
  for (int i = 1; i < n; ++i) {
    int u, v, x, y;
    std::cin >> u >> v >> x >> y;
    --u;
    --v;
    int d = std::gcd(x, y);
    x /= d;
    y /= d;
    adj[u].push_back({v, x, y});
    adj[v].push_back({u, y, x});
  }

  std::vector<int> c(n + 1), pw(n + 1);
  int ans = 0;
  auto addAns = [&](int x) {
    ans += x;
    if (ans >= M) ans -= M;
  };
  std::function<void(int, int, int)> dfs = [&](int val, int u, int fa) {
    addAns(val);
    for (auto [v, x, y] : adj[u]) if (v != fa) {
      for (int i = x, si; i > 1; i /= si) {
        si = sp[i];
        ++c[si];
        pw[si] = std::max(pw[si], c[si]);
      }
      for (int i = y, si; i > 1; i /= si) {
        si = sp[i];
        --c[si];
      }
      dfs(1LL * val * powMod(x) % M * y % M, v, u);
      for (int i = y, si; i > 1; i /= si) {
        si = sp[i];
        ++c[si];
      }
      for (int i = x, si; i > 1; i /= si) {
        si = sp[i];
        --c[si];
      }
    }
  };
  dfs(1, 0, 0);
  for (int i = 1; i <= n; ++i) if (sp[i] == i) {
    ans = 1LL * ans * powMod(i, pw[i]) % M;
  }
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  spfS();
  while (cas--) {
    solve();
  }
  return 0;
}
