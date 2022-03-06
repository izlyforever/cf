#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  if (n == 2 * k) return 0;
  for (int i = 0; i < k; ++i) {
    if (s[i] != s[n - 1 - i]) return 0;
  }
  return 1;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES\n" : "NO\n");
  }
  return 0;
}
