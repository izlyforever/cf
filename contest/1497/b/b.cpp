#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), cnt(m);
    for (auto &x : a) {
      std::cin >> x;
      ++cnt[x % m];
    }
    int r = (cnt[0] != 0);
    for (int i = 1; i * 2 < m; ++i) {
      if (cnt[i] == cnt[m - i]) {
        if (cnt[i]) ++r;
      } else {
        r += abs(cnt[i] - cnt[m - i]);
      }
    }
    if (m % 2 == 0 && cnt[m / 2]) ++r;
    std::cout << r << '\n';
  }
  return 0;
}