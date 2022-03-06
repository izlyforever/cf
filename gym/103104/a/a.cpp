#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::string s, t;
    std::cin >> s >> t;
    std::vector<int> p, a;
    for (auto x : s) p.emplace_back(x - '0');
    for (auto c : t) {
      int t = 0;
      if (c >= '0' && c <= '9') {
        t = c - '0';
      } else {
        t = c - 'A' + 10;
      }
      for (int i = 3; i >= 0; --i) {
        a.push_back(t >> i & 1);
      }
    }
    int k = p.size() - 1;
    for (int i = 0; i < k; ++i) a.emplace_back(0);
    for (int i = 0; i + k < a.size(); ++i) if (a[i]) {
      for (int j = 0; j <= k; ++j) {
        a[i + j] ^= p[j];
      }
    }
    for (int i = k; i > 0; --i) std::cout << a[a.size() - i];
    std::cout << '\n';
  }
  return 0;
}
