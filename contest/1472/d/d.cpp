#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::priority_queue<int> a[2];
    LL r[2]{};
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      a[x % 2].push(x);
    }
    a[0].push(0);
    a[1].push(0);
    for (int i = 0; i < n; ++i) {
      if (a[0].top() < a[1].top()) {
        if (i % 2 == 1) r[1] += a[1].top();
        a[1].pop();
      } else {
        if (i % 2 == 0) r[0] += a[0].top();
        a[0].pop();
      }
    }
    std::cout << (r[0] < r[1] ? "Bob" : (r[0] == r[1] ? "Tie" : "Alice")) << std::endl;
  }
  return 0;
}