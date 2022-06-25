#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int l = 0;
  while (l < n && a[l] == 0) ++l;
  if (l == n) return 0;
  int r = n;
  while (a[r - 1] == 0) --r;
  for (int i = l; i < r; ++i) if (a[i] == 0) return 2;
  return 1;
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
