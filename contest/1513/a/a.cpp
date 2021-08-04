#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    if (n >= 2 * k + 1) {
      std::vector<int> a(n);
      for (int i = 0; i <= k; ++i) a[i * 2] = i + 1;
      for (int i = 0; i < k; ++i) a[i * 2 + 1] = k + 2 + i;
      for (int i = 2 * k + 1; i < n; ++i) a[i] = i + 1;
      for (auto x : a) std::cout << x << ' ';
      std::cout << '\n';
    } else {
      std::cout << "-1\n";
    }
  }
  return 0;
}