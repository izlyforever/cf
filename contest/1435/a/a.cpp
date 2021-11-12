#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
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
    for (int i = 0; i < n; i += 2) {
      std::swap(a[i], a[i + 1]);
      a[i] = -a[i];
    }
    for (auto x : a) std::cout << x << " ";
    println;
  }
  return 0;
}