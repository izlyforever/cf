#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// 不懂哪里有问题


void solve() {
  int n, k;
  std::cin >> n >> k;

  auto f = [k](int x, int y) {
    int z = 0, c = 1;
    for (int i = 1; i <= x || i <= y; i *= k) {
          z += (x / i + y / i) % k * i;
    }
    return z;
  };
  for (int i = 0, cur = 0; i < n; ++i) {
    int tmp = f(i, cur);
    std::cout << tmp << std::endl;
    cur = f(cur, tmp);
    int x;
    std::cin >> x;
    if (x == 1) return;
  }
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