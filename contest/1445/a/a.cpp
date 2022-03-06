#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n), b(n);
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      if (a[i] + b[n - 1 - i] > x) {
        flag = false;
        break;
      }
    };
    std::cout << (flag ? "Yes\n" : "No\n");
  }
  return 0;
}
