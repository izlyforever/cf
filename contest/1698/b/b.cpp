#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int cnt = 0;
  for (int i = 1; i + 1 < n; ++i) {
    if (a[i] > a[i - 1] + a[i + 1]) ++cnt;
  }
  return k == 1 ? (n - 1) / 2 : cnt;
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
