#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  std::cin >> n >> q;
  std::vector<LL> a(n);
  for (auto& x : a) std::cin >> x;
  auto getans = [&](int x, LL y) -> LL {
    LL small = 0, ans = 0;
    for (int i = 0; i <= x; ++i) {
      y -= a[i];
      small += (a[i] << i) - a[i];
    }
    if (y <= 0) return 0;
    auto add = [&](int i, LL t) {
      ans += (t << i - x) - t;
      y -= t << i - x;
      small += (t << i) - (t << i - x);
    };
    int id = x + 1;
    while (id < n) {
      LL t = std::min(y >> id - x, a[id]);
      if (t > 0) add(id, t);
      if (t < a[id]) break;
      ++id;
    }
    if (id == n) return y > small ? -1 : y + ans;
    while (y > small) {
      --id;
      ++ans;
      if (y >> id - x) add(id, 1LL);
      if (id == x && y > 0) add(id, 1LL);
    }
    return y + ans;
  };
  while (q--) {
    int op, x;
    LL y;
    std::cin >> op >> x >> y;
    if (op == 1) a[x] = y;
    else std::cout << getans(x, y) << std::endl;
  }
  return 0;
}