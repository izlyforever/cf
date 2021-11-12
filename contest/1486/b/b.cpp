#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i] >> b[i];
    if (n % 2 == 1) {
      std::cout << 1 << "\n";
    } else {
      std::sort(a.begin(), a.end());
      std::sort(b.begin(), b.end());
      std::cout << LL(a[n / 2] - a[n / 2 - 1] + 1) * (b[n / 2] - b[n / 2 - 1] + 1) << "\n";
    }
  }
  return 0;
}