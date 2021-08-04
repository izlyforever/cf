#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout.precision(20);
  const int N = 1e7 + 2;
  auto f = [&](int n) ->double {
    double r = 0;
    if (n > N) {
      r = log(n) - log(N);
      n = N;
    }
    for (int i = 1; i <= n; ++i) r += 1.0 / i;
    return r;
  };
  int n, m, k;
  std::cin >> n >> m >> k;
  if (k >= m) {
    std::cout << std::fixed << (f(n) - f(k - 1)) * m << '\n';
  } else {
    std::cout << std::fixed << (m - k) + (f(n) - f(m - 1)) * m << '\n';
  }
  return 0;
}