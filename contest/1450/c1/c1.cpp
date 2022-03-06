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
    std::vector<std::string> s(n);
    for (auto& x : s) std::cin >> x;
    std::vector<int> a(3);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (s[i][j] == 'X') ++a[(i + j) % 3];
      }
    }
    int id = std::min_element(a.begin(), a.end()) - a.begin();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (s[i][j] == 'X' && (i + j) % 3 == id) s[i][j] = 'O';
      }
    }
    for (auto& x : s) std::cout << x << std::endl;
  }
  return 0;
}
