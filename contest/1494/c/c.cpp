#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int solve(std::vector<int>& a, std::vector<int>& b) {
  int n = a.size(), now = 0, bi = b.size() - 1;
  std::vector<int> c(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    while (bi >= 0 && b[bi] > a[i]) --bi;
    if (bi >= 0 && b[bi] == a[i]) ++now;
    c[i] = now;
  }
  a.emplace_back(INT_MAX);
  int r = now;
  now = 0;
  for (int i = 0, j = 0, m = b.size(); i < n; ++i) {
    while (j < m && b[j] < a[i]) ++j;
    if (j == m) break;
    if (a[i + 1] <= b[j]) continue;
    while (j < m && a[i + 1] > b[j]) {
      int it = std::lower_bound(b.begin(), b.begin() + j, b[j] - i) - b.begin();
      r = std::max(r, j - it + 1 + c[i + 1]);
      ++j;
    }
  }
  return r;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    int ai = std::lower_bound(a.begin(), a.end(), 0) - a.begin();
    int bi = std::lower_bound(b.begin(), b.end(), 0) - b.begin();
    std::vector<int> x, y;
    for (int i = ai; i < n; ++i) x.emplace_back(a[i]);
    for (int i = bi; i < m; ++i) y.emplace_back(b[i]);
    int r = solve(x, y);
    x.clear(); y.clear();
    for (int i = ai - 1; i >= 0; --i) x.emplace_back(-a[i]);
    for (int i = bi - 1; i >= 0; --i) y.emplace_back(-b[i]);
    std::cout << r + solve(x, y) << "\n";
  }
  return 0;
}