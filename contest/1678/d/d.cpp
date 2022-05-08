#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m;
  std::string s;
  std::cin >> n >> m >> s;
  std::vector<int> a(m), b(m);
  int ans = 0;
  for (int i = 0, cnt = 0, nm = n * m, y = 0; i < nm; ++i) {
    if (s[i] == '1') {
      if (b[y] == 0) {
        ++b[y];
        ++ans;
      }
      ++cnt;
    }
    if (i >= m && s[i - m] == '1') --cnt;
    a[y] += (cnt != 0);
    std::cout << ans + a[y] << ' ';
    if (++y == m) y = 0;
  }
  std::cout << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
