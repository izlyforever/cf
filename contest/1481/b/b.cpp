#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), b(n);
  a[0] = INT_MAX;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  int r = 0;
  for (int i = 0; i < k; ++i) {
    r = 0;
    while (r < n && a[r] >= a[r + 1]) ++r;
    if (r == n) return -1;
    ++a[r];
  }
  return r;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << "\n";
  }
  return 0;
}