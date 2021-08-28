#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 998244353;
LL inv(LL a, LL p){ // 0 < a < p and gcd(a,p) = 1
  return a == 1 ? 1 : (p - p / a) * inv(p % a, p) % p;
}
const int N = 3e5 + 2;
LL fac[N], ifac[N];
void init() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % M;
  ifac[N - 1] = inv(fac[N - 1], M);
  for (int i = N - 1; i; --i) ifac[i - 1] = ifac[i] * i % M;
}
LL binom(int n, int k) {
  //if (n < k) return 0;
  return fac[n] * ifac[k] % M * ifac[n - k] % M;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  init();
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n);
    for (auto &x : a) std::cin >> x;
    std::sort(a.begin(), a.end());
    LL r = 0;
    for (int i = 0; i < n; ++i) r += a[i + n] - a[i];
    r = r % M * binom(2*n, n) % M;
    std::cout << r << std::endl;
  }
  return 0;
}