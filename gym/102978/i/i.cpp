#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 998244353;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> vis(n);
  std::vector<int> a(m);
  for (auto &x : a) {
    std::cin >> x;
    vis[--x] = 1;
  }
  int k = 1;
  while (k < m && a[k] > a[k - 1]) ++k;
  LL r = 1;
  for (int i = 0, cnt = 0, j = 0; i < n; ++i) {
    if (j < k && i == a[j]) {
      if (++j == k) ++j;
    }
    if (vis[i]) continue;
    r = r * (j + cnt) % M;
    ++cnt;
  }
  std::cout << r << "\n";
  return 0;
}