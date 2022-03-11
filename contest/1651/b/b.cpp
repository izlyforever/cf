#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int INF = 1e9;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  std::vector<int> pw3{1};
  while (1LL * pw3.back() * 3 <= INF) {
    pw3.emplace_back(pw3.back() * 3);
  }
  while (cas--) {
    int n;
    std::cin >> n;
    if (n <= pw3.size()) {
      std::cout << "YES\n";
      for (int i = 0; i < n; ++i) {
        std::cout << pw3[i] << ' ';
      }
      std::cout << '\n';
    } else {
      std::cout << "NO\n";
    }
  }
  return 0;
}
