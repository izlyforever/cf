#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(k + 1);
    for (int i = 1; i < 2 * k - n; ++i) a[i] = i;
    for (int i = 2 * k - n; i <= k; ++i) a[i] = 3 * k - n - i;
    for (int i = 1; i <= k; ++i) std::cout << a[i] << " \n"[i == k];
  }
  return 0;
}
