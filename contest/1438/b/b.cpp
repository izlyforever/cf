#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;

int main() {;
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    bool flag = false;
    std::set<int> S;
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      if (flag) continue;
      if (S.find(x) == S.end()) S.insert(x);
      else flag = true;
    }
    std::cout << (flag ? "YES" : "NO") << std::endl;
  }
  return 0;
}