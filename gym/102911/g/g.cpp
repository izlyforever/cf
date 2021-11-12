#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, s;
  std::cin >> n >> s;
  std::vector<int> d(n), r(n);
  for (auto& x : d) std::cin >> x;
  for (auto& x : r) std::cin >> x;
  std::priority_queue<int> mx;
  int i, ans = 0;
  for (i = 0; i < n; ++i) {
    while (!mx.empty() && s < d[i]) {
      s += mx.top();
      mx.pop();
      ++ans;
    }
    if (s < d[i]) break;
    s -= d[i];
    mx.push(r[i]);
  }
  if (i == n) std::cout << "WIN\n" << ans << "\n";
  else std::cout << "LOSE\n" << i << "\n";
  return 0;
}