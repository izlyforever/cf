#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int INF = 5e8;
std::vector<int> solve(const std::vector<int>& a, int m) {
  int n = a.size();
  std::vector<int> id(n), ai(n);
  std::iota(id.begin(), id.end(), 0);
  std::sort(id.begin(), id.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  for (int i = 0; i < n; ++i) ai[id[i]] = i;
  int p;
  std::vector<int> b(m);
  std::vector<std::set<int>> c(m);
  std::cin >> p;
  for (int i = 0, x, y; i < p; ++i) {
    std::cin >> x >> y;
    --x; --y;
    c[y].insert(ai[x]);
  }
  auto mex = [&](const std::set<int>& d) {
    for (int i = 0; i < n; ++i) if (!d.count(i)) return i;
    return n;
  };
  for (int i = 0; i < m; ++i) {
    int j = mex(c[i]);
    b[i] = (j == n ? INF : a[id[j]]);
  }
  return b;
};
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n[4];
  for (int i = 0; i < 4; ++i) std::cin >> n[i];
  std::vector<int> a[4];
  for (int i = 0; i < 4; ++i) a[i].resize(n[i]);
  for (int i = 0; i < 4; ++i) for (auto& x : a[i]) std::cin >> x;
  for (int i = 1; i < 4; ++i) {
    auto t = solve(a[i - 1], n[i]);
    for (int j = 0; j < n[i]; ++j) a[i][j] += t[j];
  }
  int mx = *std::min_element(a[3].begin(), a[3].end());
  std::cout << (mx < INF ? mx : -1) << "\n";
  return 0;
}
