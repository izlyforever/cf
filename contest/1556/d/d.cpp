#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;


int add(int i, int j) {
  int x, y;
  std::cout << "and " << i << ' ' << j << std::endl;
  std::cin >> x;
  std::cout << "or " << i << ' ' << j << std::endl;
  std::cin >> y;
  return x + y;
}

void solve() {
  int n, k;
  std::cin >> n >> k;
  int a = add(1, 2);
  int b = add(1, 3);
  int c = add(2, 3);
  std::vector<int> ans{(a + b - c) / 2, (a + c - b) / 2, (b + c - a) / 2};
  for (int i = 4; i <= n; ++i) {
    ans.emplace_back(add(1, i) - ans[0]);
  }
  std::sort(ans.begin(), ans.end());
  std::cout << "finish " << ans[k - 1] << std::endl;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}