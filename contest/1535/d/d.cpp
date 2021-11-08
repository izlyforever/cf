#include <bits/stdc++.h>
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    int k;
    std::string s;
    std::cin >> k >> s;
    int n = (1 << k);
    std::vector<int> a(n * 2, 1);
    auto pushUp = [&](int p) -> void {
      switch (s[s.size() - p]) {
        case '?': a[p] = a[p] = a[p << 1] + a[p << 1 | 1]; break;
        case '1': a[p] = a[p << 1]; break;
        default: a[p] = a[p << 1 | 1]; break;
      }
    };
    std::function<void(int)> build = [&](int p) {
      if (p >= n) return;
      build(p << 1);
      build(p << 1 | 1);
      pushUp(p);
    };
    build(1);
    int q;
    std::cin >> q;
    while (q--) {
      int p;
      char c;
      std::cin >> p >> c;
      int x = n - p;
      s[--p] = c;
      while (x) {
        pushUp(x);
        x >>= 1;
      }
      std::cout << a[1] << '\n';
    }
  }
  return 0;
}