#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a;
  while (n) {
    a.emplace_back(n % 10);
    n /= 10;
  }
  auto f = [&](int i) {
    return std::min(i + 1, 19 - i);
  };
  int ans = 0;
  std::function<void(int, int)> dfs = [&](int x, int i) {
    if (i < 0) {
      ans += x;
    } else {
      dfs(x * f(a[i]), i - 1);
      if (i > 1 && a[i] > 0) {
        a[i - 2] += 10;
        dfs(x * f(a[i] - 1), i - 1);
        a[i - 2] -= 10;
      }
    }
  };
  dfs(1, a.size() - 1);
  std::cout << ans - 2 << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
