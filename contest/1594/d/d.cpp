#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
int solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> e(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::string s;
    std::cin >> x >> y >> s;
    --x; --y;
    e[x].emplace_back(y, s[0] == 'i');
    e[y].emplace_back(x, s[0] == 'i');
  }
  int ans = n;
  std::vector<int> val(n, -1);
  for (int i = 0; i < n; ++i) if (val[i] == -1) {
    std::queue<int> Q;
    val[i] = 0;
    Q.push(i);
    int cnt[2]{0, 0};
    while (!Q.empty()) {
      int u = Q.front();
      ++cnt[val[u]];
      Q.pop();
      for (auto [v, w] : e[u]) {
        int x = val[u] ^ w;
        if (val[v] == -1) {
          val[v] = x;
          Q.push(v);
        } else if (val[v] != x) {
          return -1;
        }
      }
    }
    ans -= std::min(cnt[0], cnt[1]);
  }
  return ans;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}