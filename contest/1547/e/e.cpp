#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n, k;
  std::cin >> n >> k;
  // std::cerr << n << ' ' << k << '\n';
  std::vector<std::pair<int, int>> a(k);
  for (auto& [x, y] : a) std::cin >> x;
  for (auto& [x, y] : a) std::cin >> y;
  std::sort(a.begin(), a.end());
  std::stack<int> Q;
  for (int i = 0; i < k; ++i) {
    if (!Q.empty() && a[Q.top()].second + (a[i].first - a[Q.top()].first) <= a[i].second) continue;
    while (!Q.empty() && a[i].second + (a[i].first - a[Q.top()].first) <= a[Q.top()].second) Q.pop();
    Q.push(i);
  }
  int j = Q.top();
  Q.pop();
  std::vector<int> ans(n + 1);
  for (int i = n; i > 0; --i) {
    ans[i] = a[j].second + abs(i - a[j].first);
    if (!Q.empty()) {
      ans[i] = std::min(ans[i], a[Q.top()].second + abs(i - a[Q.top()].first));
      if (i == a[Q.top()].first) {
        j = Q.top();
        Q.pop();
      }
    }
  }
  for (int i = 1; i <= n; ++i) std::cout << ans[i] << " \n"[i == n];
}

int main() {
  // freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}