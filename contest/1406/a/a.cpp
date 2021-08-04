#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int a[102]={};
    int n;
    std::cin >> n;
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      ++a[x];
    }
    int r = 0;
    while (a[r]) {
      --a[r];
      ++r;
    }
    int ans = r;
    r = 0;
    while (a[r]) {
      --a[r];
      ++r;
    }
    std::cout << r + ans << std::endl;
  }
  return 0;
}