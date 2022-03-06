#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

LL solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  if (![&]() {
    if (n == 3) return a[1] % 2 == 0;
    for (int i = 1; i < n - 1; ++i) {
      if (a[i] > 1) return true;
    }
    return false;
  }()) return -1;
  LL ans = 0;
  for (int i = 1; i < n - 1; ++i) {
    ans += (a[i] + 1) / 2;
  }
  return ans;
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
