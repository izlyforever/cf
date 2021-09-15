#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  const LL M = 1e9 + 7;
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    int s = INT_MAX;
    for (auto x : a) s &= x;
    int x = std::count(a.begin(), a.end(), s);
    LL r = LL(x - 1) * x % M;
    for (int i = n - 2; i > 0; --i) r = r * i % M;
    std::cout << r << '\n';
  }
  return 0;
}