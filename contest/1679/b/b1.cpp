#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n), b(n);
  for (auto &x : a) std::cin >> x;
  LL sm = std::accumulate(a.begin(), a.end(), 0LL);
  int last = -1, cnt = 0;
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int i, x;
      std::cin >> i >> x;
      sm += x - (b[--i] == cnt ? a[i] : last);
      a[i] = x;
      b[i] = cnt;
    } else {
      int x;
      std::cin >> x;
      last = x;
      ++cnt;
      sm = 1LL * n * x;
    }
    std::cout << sm << '\n';
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
