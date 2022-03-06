#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<std::string> s(n);
  for (auto& x : s) std::cin >> x;
  if (n >= 2 * k) {
    std::cout << "YES\n";
    for (int i = 0; i < n; ++i) std::cout << s[(i + n - k) % n] << " \n"[i == n - 1];
  } else std::cout << "NO\n";
  return 0;
}
