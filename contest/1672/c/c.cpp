#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int l = 1;
  while (l < n && a[l - 1] != a[l]) ++l;
  if (l == n) return 0;
  int r = n - 2;
  while (r >= 0 && a[r + 1] != a[r]) --r;
  if (r > l) return r - l;
  if (l == r) return 1;
  return 0;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}
