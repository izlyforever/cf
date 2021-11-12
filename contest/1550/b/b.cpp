#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

int solve() {
    int n, a, b;
    std::string s;
    std::cin >> n >> a >> b >> s;
    if (b >= 0) return (a + b) * n;
    int x = 1;
    for (int i = 1; i < n; ++i) if (s[i] != s[i - 1]) ++x;
    return a * n + b * (x / 2 + 1);
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