#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;

int main() {;
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int s = 0;
  for (auto& x : a) {
    std::cin >> x;
    s ^= x;
  }
  if (n % 2 == 0) {
    if (s) {
      std::cout << "NO\n";
      return 0;
    }
    --n;
  }
  std::cout << "YES\n";
  std::cout << n - 2 << "\n";
  for (int i = 3; i <= n; i += 2) std::cout << i - 2 << " " << i - 1 << " " << i << "\n";
  for (int i = n - 2; i >= 3; i -= 2) std::cout << n << " " << i - 1 << " " << i - 2 << "\n";
  return 0;
}