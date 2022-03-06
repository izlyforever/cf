#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

LL query(int l, int r) {
  std::cout << "? " << l << ' ' << r << std::endl;
  LL x;
  std::cin >> x;
  return x;
}

void solve() {
  int n;
  std::cin >> n;
  LL tot = query(1, n);
  int l = 1, r = n;
  while (l <= r) {
    int m = (l + r) / 2;
    if (query(1, m) == tot) r = m - 1;
    else l = m + 1;
  }
  int k = l;
  LL totK = query(1, k - 1);
  int j = k - (tot - totK);

  tot = query(1, j - 1);
  totK = query(1, j - 2);
  int i = j - 1 - (tot - totK);
  
  std::cout << "! " << i << ' ' << j << ' ' << k << std::endl;
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
