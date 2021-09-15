#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

const LL M = 1e9+7;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, x, pos;
  std::cin >> n >> x >> pos;
  std::vector<int> ans;
  int l = 0, r = n;
  while (l < r) {
    int m = (l + r) / 2;
    if (m <= pos) {
      if (m != pos) ans.emplace_back(0);
      l = m + 1;
    } else {
      ans.emplace_back(1);
      r = m;
    }
  }
  int mx = x - 1, px = n - x;
  LL ret = 1;
  for (auto& x : ans) {
    if (x == 1) {
      ret = ret * px % M;
      --px;
    } else {
      ret = ret * mx % M;
      --mx;
    }
  }
  for (int i = n - ans.size() - 1; i > 0; --i) ret = ret * i % M;
  print(ret);
  return 0;
}