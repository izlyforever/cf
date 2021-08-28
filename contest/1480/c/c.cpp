#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  auto query = [&](int x) {
    if (a[x]) return a[x];
    std::cout << "? " << x << std::endl;
    int r;
    std::cin >> r;
    return r;
  };
  a[1] = query(1);
  if (a[1] == 1) return 1;
  a[2] = query(2);
  if (a[2] > a[1]) return 1;

  a[n] = query(n);
  if (a[n] == 1) return n;
  a[n - 1] = query(n - 1);
  if (a[n - 1] > a[n]) return n;

  int l = 2, r = n - 1;
  while (l < r) {
    int m = (l + r) / 2;
    a[m] = query(m);
    a[m + 1] = query(m + 1);
    if (a[m] > a[m + 1]) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return r;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int r = solve();
  std::cout << "! " << r << std::endl;
  return 0;
}