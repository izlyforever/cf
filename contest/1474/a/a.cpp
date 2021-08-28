#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::string a;
    std::cin >> n >> a;
    std::string b;
    int now = 0;
    for (int i = 0; i < n; ++i) {
      int t = a[i] - '0' + 1;
      if (t == now) {
        b += '0';
        --now;
      } else {
        b += '1';
        now = t;
      }
    }
    std::cout << b << "\n";
  }
  return 0;
}