#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> p{{1, 8}, {6, 18}, {28, 28}, {88, 58}, {198, 128}, {328, 198}, {648, 388}};
  std::vector<int> r(n + 1);
  for (auto [v, w] : p) {
    for (int j = n; j >= v; --j) {
      r[j] = std::max(r[j], r[j - v] + w);
    }
  }
  std::cout << r[n] + n * 10 << std::endl;
  return 0;
}