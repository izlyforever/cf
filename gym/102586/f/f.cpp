#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), d(n);
  for (auto& x : a) std::cin >> x;
  for (auto& x : b) std::cin >> x;
  for (int i = 0; i < n; ++i) d[i] = abs(a[i] - b[i]);
  std::cout << std::accumulate(d.begin(), d.end(), 0LL) << '\n';
  std::vector<int> cur[2], ans;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= b[i]) {
      while (!cur[1].empty()) {
        if (d[cur[1].back()] > d[i]) {
          ans.emplace_back(i);
          break;
        }
        ans.emplace_back(cur[1].back());
        cur[1].pop_back();
      }
      if (cur[1].empty()) cur[0].emplace_back(i);
    } else cur[1].emplace_back(i);
  }
  for (auto i : cur[0]) ans.emplace_back(i);
  std::reverse(cur[1].begin(), cur[1].end());
  for (auto i : cur[1]) ans.emplace_back(i);
  for (auto x : ans) std::cout << x + 1 << ' ';
  std::cout << '\n';
  return 0;
}