#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int query(int l, int r) {
  std::cout << "? " << ++l << ' ' << r << std::endl;
  int x;
  std::cin >> x;
  return x;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, t, k;
  std::cin >> n >> t >> k;
  int l = 0, r = n;
  while (r - l > 1) {
    int m = (l + r) / 2;
    int x = query(l, m);
    if (k <= m - l - x) r = m;
    else {
      k -= m - l - x;
      l = m;
    }
  }
  std::cout << "! " << r << std::endl;
  return 0;
}