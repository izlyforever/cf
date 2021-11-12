#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

bool solve() {
  LL s, n, k;
  std::cin >> s >> n >> k;
  if (s == k) return true;
  LL x = n / k * 2 * k + n % k;
  return s < x;
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