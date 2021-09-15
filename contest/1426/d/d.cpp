#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<LL> a(n);
  for (auto& x : a) std::cin >> x;
  std::set<LL> s;
  int r = 0;
  LL sa = 0;
  for (auto x : a) {
    if (s.find(-x - sa) != s.end()) {
      s.clear();
      sa = 0;
      ++r;
    }
    sa += x;
    s.insert(x - sa);
  }
  print(r);
  return 0;
}