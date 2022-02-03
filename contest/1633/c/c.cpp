#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  LL hc, dc, hm, dm;
  std::cin >> hc >> dc >> hm >> dm;
  auto check = [&](LL h, LL d) {
    return (h + dm - 1) / dm >=  (hm + d - 1) / d;
  };
  int k, w;
  LL a;
  std::cin >> k >> w >> a;
  for (int i = 0; i <= k; ++i) {
    if (check(hc + a * i, dc + (k - i) * w)) return true;
  }
  return false;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}