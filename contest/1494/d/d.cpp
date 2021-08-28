#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n, std::vector<int>(n));
  for (auto &x : a) for (auto &i : x) std::cin >> i;
  std::vector<int> p(n), c(n);
  std::iota(p.begin(), p.end(), 0);
  std::vector<std::tuple<int, int, int>> b;
  for (int i = 0; i < n; ++i) {
    c[i] = a[i][i];
    for (int j = i + 1; j < n; ++j) {
      b.emplace_back(a[i][j], i, j);
    }
  }
  std::sort(b.begin(), b.end());
  auto find = [&](int x) {
    while (x != p[x]) x = p[x];
    return x;
  };
  for (auto [w, i, j] : b) {
    int fi = find(i), fj = find(j);
    if (std::max(c[fi], c[fj]) < w) {
      p[fi] = p[fj] = n;
      p.emplace_back(n);
      c.emplace_back(w);
      ++n;
    } else {
      if (c[fi] == w) p[fj] = fi;
      else p[fi] = fj;
    }
  }
  std::cout << n << "\n";
  for (auto &x : c) std::cout << x << " ";
  std::cout << "\n" << n << "\n";
  for (int i = 0; i + 1 < n; ++i) {
    std::cout << i + 1 << " " << p[i] + 1 << "\n";
  }
  return 0;
}