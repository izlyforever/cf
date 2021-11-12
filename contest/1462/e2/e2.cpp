#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
const int M = 1e9 + 7;
const int N = 2e5 + 2;
LL fac[N], ifac[N];
LL inv(LL a, LL p){ // 0 < a < p and gcd(a,p) = 1
  return a == 1 ? 1 : (p - p / a) * inv(p % a, p) % p;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % M;
  ifac[N - 1] = inv(fac[N - 1], M);
  for (int i = N - 1; i; --i) ifac[i - 1] = ifac[i] * i % M;
}
LL binom(int n, int k) {
  if (n < k || n < 0) return 0;
  return fac[n] * ifac[k] % M * ifac[n - k] % M;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::sort(a.begin(), a.end());
    LL r = 0;
    for (int i = 0; i + m <= n; ++i) {
      int it = std::upper_bound(a.begin(), a.end(), a[i] + k) - a.begin();
      r += binom(it - i - 1, m - 1);
    }
    std::cout << r % M << std::endl;
  }
  return 0;
}