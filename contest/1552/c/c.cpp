#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(2 * n, n);
  for (int i = 0; i < k; ++i) {
    int x, y;
    std::cin >> x >> y;
    a[--x] = a[--y] = i;
  }
  int x = 0;
  for (int _ = 0; _ < 2; ++_) {
    for (int i = k; i < n; ++i) {
      while (a[x] != n) if (++x == 2 * n) x = 0;
      a[x] = i;
    }
  }
  std::vector<int> ans(n, -1);
  for (int i = 0; i < 2 * n; ++i) if (ans[a[i]] == -1) {
    int j = 1, now = 0;
    std::vector<int> cnt(n);
    while (j < 2 * n) {
      int tmp = a[(i + j) % (2 * n)];
      if (tmp == a[i]) break;
      if (cnt[tmp]++) --now;
      else ++now;
      ++j;
    }
    ans[a[i]] = now;
  }
  std::cout << std::accumulate(ans.begin(), ans.end(), 0) / 2 << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}
