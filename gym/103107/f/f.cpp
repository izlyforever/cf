#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

std::vector<int> spf(int N) {
  std::vector<int> sp(N), p{0, 2};
  for (int i = 2; i < N; i += 2) sp[i] = 2;
  for (int i = 1; i < N; i += 2) sp[i] = i;
  for (int i = 3; i < N; i += 2) {
    if (sp[i] == i) p.emplace_back(i);
    for (int j = 2, np = p.size(); j < np && p[j] <= sp[i] && i * p[j] < N; ++j) {
      sp[i * p[j]] = p[j]; // 注意到sp只被赋值一次
    }
  }
  return sp;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  auto sp = spf(n + 1);
  auto f = [&](int x) {
    if (x == 1) return 1;
    int ans = 1, px = sp[x], cnt = 0;
    while (x % px == 0) {
      x /= px;
      if (cnt) ans *= px;
      cnt = !cnt;
    }
    return ans * x;
  };
  LL ans = 0;
  for (int i = 1; i <= n; ++i) ans += f(i);
  std::cout << ans << '\n';
  return 0;
}
