#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  if ((n - 1) % b == 0) return true;
  if (a == 1) return false;
  for (LL x = a; x <= n; x *= a) if ((n - x) % b == 0) return true;
  return false;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Yes" : "No") << '\n';
  }
  return 0;
}
