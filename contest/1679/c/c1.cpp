#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::set<int> r, c;
  for (int i = 1; i <= n; ++i) r.insert(i);
  for (int i = 1; i <= n; ++i) c.insert(i);
  auto check = [&](int x1, int y1, int x2, int y2) {
    auto ri = r.lower_bound(x1);
    if (ri == r.end() || *ri > x2) return true;
    auto ci = c.lower_bound(y1);
    if (ci == c.end() || *ci > y2) return true;
    return false;
  };
  std::vector<int> nr(n + 1), nc(n + 1);
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 3) {
      int x1, y1, x2, y2;
      std::cin >> x1 >> y1 >> x2 >> y2;
      std::cout << (check(x1, y1, x2, y2) ? "Yes" : "No") << '\n';
    } else {
      int p = (op == 1 ? 1 : -1);
      int x, y;
      std::cin >> x >> y;
      nr[x] += p;
      if (nr[x] == 0) {
        r.insert(x);
      } else {
        r.erase(x);
      }
      nc[y] += p;
      if (nc[y] == 0) {
        c.insert(y);
      } else {
        c.erase(y);
      }
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
