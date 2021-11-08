#include <bits/stdc++.h>
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<LL> a(n), f;
  f = {0};
  for (auto& x : a) {
    std::cin >> x;
    std::vector<LL> g;
    g.emplace_back(f[0]);
    for (int i = 1; i < f.size(); ++i) {
      g.emplace_back(std::max(f[i], f[i - 1] + x));
    }
    if (f.back() + x >= 0) g.emplace_back(f.back() + x);
    std::swap(f, g);
  }
  std::cout << f.size() - 1 << '\n';
  return 0;
}