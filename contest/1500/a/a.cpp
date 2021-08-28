#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int N = 5e6 + 2;

std::optional<std::tuple<int, int, int, int>> solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::vector<std::array<int, 2>> p(N);
  int x = -1;
  for (int i = 0; i < n; ++i) {
    if (p[a[i]][0] == 0) {
      p[a[i]][0] = i + 1;
    } else if (p[a[i]][1] == 0) {
      p[a[i]][1] = i + 1;
      if (x != -1) return std::make_tuple(p[a[i]][0], p[x][0], p[x][1], p[a[i]][1]);
      x = a[i];
    }
  }
  std::vector<std::array<int, 2>> r(N);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      int x = a[i] + a[j];
      if (r[x][0] == r[x][1]) {
        r[x][0] = i + 1;
        r[x][1] = j + 1;
      } else if (std::set{r[x][0], r[x][1], i + 1, j + 1}.size() == 4) {
        return std::make_tuple(r[x][0], r[x][1], i + 1, j + 1);
      }
    }
  }
  return {}; // 必须要加，否则会 RE
}


int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  auto r = solve();
  if (r.has_value()) {
    std::cout << "YES\n";
    auto [x, y, z, w] = r.value();
    std::cout << x << ' ' << y << ' ' << z << ' ' << w << '\n';
  } else std::cout << "NO\n";
  return 0;
}