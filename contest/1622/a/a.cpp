#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  std::vector<int> a(3);
  std::cin >> a[0] >> a[1] >> a[2];
  std::sort(a.begin(), a.end());
  if (a[0] + a[1] == a[2]) return true;
  if (a[0] == a[1]) return a[2] % 2 == 0;
  return a[1] == a[2] && a[0] % 2 == 0;
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
