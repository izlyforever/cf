#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    bool flag = false;
    for (int i = 1; i < n; ++i) if (a[i - 1] <= a[i]) {
      flag = true;
      break;
    }
    std::cout << (flag ? "YES" : "NO") << std::endl;
  }
  return 0;
}