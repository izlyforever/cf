#include <bits/stdc++.h>
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  int ans = 0;
  // std::multiset<int> S{0}; // 确保 S 非空，保证安全
  std::priority_queue<int> Q; // 优先队列比 set 快
  Q.push(0);
  LL now = 0;
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    if (x >= 0) {
      ++ans;
      now += x;
    } else {
      x = -x;
      if (now >= x) {
        ++ans;
        now -= x;
        Q.push(x);
      } else {
        if (Q.top() > x) {
          now += Q.top() - x;
          Q.pop();
          Q.push(x);
        }
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}