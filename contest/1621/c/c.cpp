#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int query(int x) {
  std::cout << "? " << x + 1 << std::endl;
  std::cin >> x;
  return --x;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n, -1);
  for (int i = 0; i < n; ++i) if (p[i] == -1) {
    while (query(i) != i);
    int x = query(i);
    p[i] = x;
    while (x != i) {
      int y = query(i);
      p[x] = y;
      x = y;
    }
  }
  std::cout << "! ";
  for (int i = 0; i < n; ++i) {
    std::cout << p[i] + 1 << ' ';
  }
  std::cout << std::endl;
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