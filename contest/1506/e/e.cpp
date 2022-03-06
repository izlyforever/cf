#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> q(n), mn(n), mx(n);
    for (auto& x : q) std::cin >> x;
    std::set<int> Smx, Smn;
    for (int i = 1; i < q[0]; ++i) Smn.insert(i), Smx.insert(-i);
    mx[0] = mn[0] = q[0];
    for (int i = 1; i < n; ++i) {
      if (q[i] == q[i - 1]) {
        mn[i] = *Smn.begin();
        Smn.erase(Smn.begin());
        mx[i] = -*Smx.begin();
        Smx.erase(Smx.begin());
      } else {
        mn[i] = mx[i] = q[i];
        for (int j = q[i - 1] + 1; j < q[i]; ++j) Smn.insert(j), Smx.insert(-j);
      }
    }
    for (int i = 0; i < n; ++i) std::cout << mn[i] << " \n"[i == n - 1];
    for (int i = 0; i < n; ++i) std::cout << mx[i] << " \n"[i == n - 1];
  }
  return 0;
}
