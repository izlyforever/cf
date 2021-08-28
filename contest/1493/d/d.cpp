#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

std::vector<int> spf(int N) {
  std::vector<int> sp(N), p{0, 2};
  for (int i = 2; i < N; i += 2) sp[i] = 2;
  for (int i = 1; i < N; i += 2) sp[i] = i;
  for (int i = 3; i < N; i += 2) {
    if (sp[i] == i) p.emplace_back(i);
    for (int j = 2; j < p.size() && p[j] <= sp[i] && i * p[j] < N; ++j) {
      sp[i * p[j]] = p[j]; // 注意到sp只被赋值一次
    }
  }
  return sp;
}
const LL M = 1e9 + 7;
int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  const int N = 2e5 + 2;
  auto sp = spf(N);
  int n, q;
  std::cin >> n >> q;
  std::vector<std::map<int, int>> a(n);
  std::vector<std::multiset<int>> ans(N);
  LL r = 1;
  auto add = [&](int i, int x) {
    while (x != 1) {
      int sx = sp[x], c = 0;
      while (sp[x] == sx) x /= sx, ++c;
      int mn = 0;
      if (ans[sx].size() == n) {
        mn = *ans[sx].begin();
      }
      int lst = a[i][sx];
      if (lst) ans[sx].erase(ans[sx].find(lst));
      a[i][sx] += c;
      ans[sx].insert(a[i][sx]);
      if (ans[sx].size() == n) {
        for (int i = *ans[sx].begin(); i > mn; --i) r = r * sx % M;
      }
    }
  };
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    add(i, x);
  }
  while (q--) {
    int i, x;
    std::cin >> i >> x;
    add(--i, x);
    std::cout << r << "\n";
  }
  return 0;
}