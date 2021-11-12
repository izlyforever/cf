#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// O(N) 预处理所有数的(是否算重)素因子个数
std::pair<std::vector<int>, std::vector<int>> npf(int N) {
  std::vector<int> np(N, 1), nps(N, 1), p{0, 2};
  nps[0] = nps[1] = 0;
  np[0] = np[1] = 0;
  for (int i = 3; i < N; i += 2) {
    if (nps[i] == 1) p.emplace_back(i);
    for (int j = 2, t; j < p.size() && (t = i * p[j]) < N; ++j) {
      nps[t] = nps[i] + 1;
      np[t] = np[i];
      if (i % p[j] == 0) break;
      ++np[t];
    }
  }
  for (int i = 2; i < N; i += 4) np[i] = np[i >> 1] + 1;
  for (int i = 4; i < N; i += 4) np[i] = np[i >> 1];
  for (int i = 2; i < N; i += 2) nps[i] = nps[i >> 1] + 1;
  return {np, nps};
}

int solve(const std::vector<int>& f) {
  int a, b, c;
  std::cin >> a >> b >> c;
  int d = std::gcd(a, b);
  if (c % d) return 0;
  c /= d;
  a /= d;
  b /= d;
  auto cal = [&](int x) {
    return x % a ? 0 : 1 << f[x / a];
  };
  int r = 0;
  for (int i = 1; i * i <= c; ++i) if (c % i == 0) {
    r += cal(b + i);
    if (i * i != c) r += cal(b + c / i);
  }
  return r;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  auto [f, _] = npf(2e7 + 2);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve(f) << '\n';
  }
  return 0;
}