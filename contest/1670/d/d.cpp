#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int M = 5e8 + 1;
std::vector<int> ans;

void init() {
  ans = std::vector<int>{0};
  int now = 0, i = 0;
  while (now < M) {
    for (int j = 0; j < 3; ++j) {
      now += 2 * i + j;
      ans.emplace_back(now);
    }
    ++i;
  }
}

void solve() {
  int n;
  std::cin >> n;
  std::cout << std::lower_bound(ans.begin(), ans.end(), (n + 1) / 2) - ans.begin() << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
