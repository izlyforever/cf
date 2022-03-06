#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 998244353;
const LL inv2 = (M + 1) / 2;
const LL inv4 = inv2 * inv2 % M;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> s(n);
  for (auto& x : s) std::cin >> x;
  const int N = std::max(n, m);
  std::vector<LL> p(N);
  p[1] = inv4;
  for (int i = 2; i < N; ++i) p[i] = (1 + (M - p[i - 1]) * 2) * inv4 % M;
  for (int i = 2; i < N; ++i) {
    p[i] += p[i - 1];
    if (p[i] >= M) p[i] -= M;
  }
  LL w = 1;
  for (auto& x : s) {
    for (auto c : x) if (c == 'o') {
      w *= 2;
      if (w >= M) w -= M;
    }
  }
  LL r = 0;
  for (int i = 0; i < n; ++i) {
    int j = 0;
    while (j < m) {
      while (j < m && s[i][j] == '*') ++j;
      if (j == m) break;
      int now = j;
      while (j < m && s[i][j] == 'o') ++j;
      r += p[j - now - 1];
    }
  }
  for (int j = 0; j < m; ++j) {
    int i = 0;
    while (i < n) {
      while (i < n && s[i][j] == '*') ++i;
      if (i == n) break;
      int now = i;
      while (i < n && s[i][j] == 'o') ++i;
      r += p[i - now - 1];
    }
  }
  std::cout << r % M * w % M << '\n';
  return 0;
}
