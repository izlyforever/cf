#include <bits/stdc++.h>
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<int, int>> a(n);
  std::vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    int p, v;
    std::cin >> p >> v;
    a[i] = {p, i};
    b[i] = p + v * k;
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  for (int i = 0; i < n; ++i) a[i].first = b[i];
  for (int i = 0; i < n; ++i) b[a[i].second] = a[i].first;
  for (int i = 0; i < n; ++i) std::cout << b[i] << " \n"[i == n - 1];
  return 0;
}