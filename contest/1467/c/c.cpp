#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n[3]{};
  std::cin >> n[0] >> n[1] >> n[2];
  LL r = 0;
  std::vector<std::vector<int>> a(3);
  std::vector<int> c;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0, x; j < n[i]; ++j) {
      std::cin >> x;
      a[i].emplace_back(x);
      r += x;
    }
  }
  std::vector<int> b;
  for (int i = 0; i < 3; ++i) {
    b.emplace_back(*std::min_element(a[i].begin(), a[i].end()));
  }
  std::sort(b.begin(), b.end());
  LL ans = r - b[0] * 2 - b[1] * 2;
  for (int i = 0; i < 3; ++i) {
    LL tmp = r;
    for (int j = 0; j < n[i]; ++j) tmp -= a[i][j] * 2;
    ans = std::max(ans, tmp);
  }
  std::cout << ans << std::endl;
  return 0;
}