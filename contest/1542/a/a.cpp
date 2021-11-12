#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(2 * n);
  for (auto& x : a) std::cin >> x, x &= 1;
  return n == std::count(a.begin(), a.end(), 1);
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