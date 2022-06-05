#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int query(const std::string& s) {
  std::cout << "? " << s << std::endl;
  int x;
  std::cin >> x;
  return x;
}

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(m);
  for (int i = 0; i < m; ++i) {
    std::string s(m, '0');
    s[i] = '1';
    a[i] = query(s);
  }
  std::vector<int> p(m);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  int ans = 0;
  std::string now(m, '0');
  for (int i = 0; i < m; ++i) {
    int x = p[i];
    auto nowx = now;
    nowx[x] = '1';
    int ansx = query(nowx);
    if (ansx == ans + a[x]) {
      std::swap(now, nowx);
      ans = ansx;
    }
  }
  std::cout << "! " << ans << std::endl;
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
