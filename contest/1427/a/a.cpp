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
    int r = 0;
    for (auto& x : a) {
      std::cin >> x;
      r += x;
    };
    if (r == 0) print("NO");
    else {
      print("YES");
      if (r > 0) std::sort(a.begin(), a.end(), std::greater<>());
      else std::sort(a.begin(), a.end());
      for (auto x : a) std::cout << x << " ";
      println;
    }
  }
  return 0;
}
