#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

using Node = std::vector<std::pair<int, LL>>;

Node f(std::vector<int> a, int m) {
  Node ans;
  for (auto &x : a) {
    int t = 1;
    while (x % m == 0) {
      t *= m;
      x /= m;
    }
    ans.emplace_back(x, t);
  }
  Node ret;
  auto [x, cnt] = ans[0];
  for (int i = 1, n = ans.size(); i < n; ++i) {
    if (ans[i].first != ans[i - 1].first) {
      ret.emplace_back(x, cnt);
      std::tie(x, cnt) = ans[i];
    } else {
      cnt += ans[i].second;
    }
  }
  ret.emplace_back(x, cnt);
  return ret;
}

bool solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int k;
  std::cin >> k;
  std::vector<int> b(k);
  for (auto &x : b) std::cin >> x;
  return f(a, m) == f(b, m);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Yes" : "No") << '\n';
  }
  return 0;
}
