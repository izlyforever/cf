#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    a[i] = i - a[i];
  }
  for (int i = 1; i <= n; ++i) {
    std::cin >> b[i];
    b[i] += i;
  }
  // a[i] 表示从 i 最多能跑到 a[i]
  // b[i] 表示从 i 将会滑落到 b[i]
  std::vector<int> dist(n + 1, INT_MAX), p(n + 1), pp(n + 1);
  dist[n] = 0;
  std::queue<int> Q;
  Q.push(n);
  int last = n; // 这里的 last 特别关键，也是不 TLE 的原因
  // 因为每次都是不能到达一段区间后掉下去，那么掉下去的再起来如果比它大就没有必要考虑了
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    if (a[u] < last) {
      for (int i = a[u]; i < last; ++i) if (dist[b[i]] == INT_MAX) {
        dist[b[i]] = dist[u] + 1;
        p[b[i]] = u;
        pp[b[i]] = i;
        Q.push(b[i]);
      }
      last = a[u];
    }
  }
  if (dist[0] == INT_MAX) {
    std::cout << -1 << '\n';
  } else {
    std::cout << dist[0] << '\n';
    std::vector<int> ans{0};
    for (int i = p[0]; i != n; i = p[i]) {
      ans.emplace_back(pp[i]);
    }
    for (int i = ans.size() - 1; i >=0; --i) {
      std::cout << ans[i] << " \n"[i == 0];
    }
  }
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
