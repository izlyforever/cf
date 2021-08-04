#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  int n;
  LL k, x;
  std::cin >> n >> k;
  std::vector<LL> a(n);
  for (auto &x : a) std::cin >> x;
  LL mn = *std::min_element(a.begin(), a.end());
  LL t = 0;
  for (auto x : a) t = std::__gcd(t, x - mn);
  return (k - mn) % t == 0;
  return 0;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES\n" : "NO\n");
  }
  return 0;
}