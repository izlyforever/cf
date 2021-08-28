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
    std::string s;
    std::cin >> n >> k >> s;
    std::vector<int> a;
    for (int i = 0; i < n; ++i) if (s[i] == '*') a.emplace_back(i);
    int r = 1, an = a.size(), lst = a[0];
    for (int i = 1; i < an; ++i) {
      if (a[i] - lst > k) {
        ++r;
        lst = a[i - 1];
      }
    }
    if (lst != a.back()) ++r;
    std::cout << r << '\n';
  }
  return 0;
}