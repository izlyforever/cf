#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int M = 1e9 + 7;
const int N = 1e4 + 2;

LL inv(LL a, LL p){ // 0 < a < p and gcd(a,p) = 1
  return a == 1 ? 1 : (p - p / a) * inv(p % a, p) % p;
}
LL fac[N], ifac[N];
void init() {
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % M;
  ifac[N - 1] = inv(fac[N - 1], M);
  for (int i = N - 1; i; --i) ifac[i - 1] = ifac[i] * i % M;
}
LL binom(int n, int k) {
  //if (n < k || n < 0) return 0;
  return fac[n] * ifac[k] % M * ifac[n - k] % M;
}
int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    std::sort(a.rbegin(), a.rend());
    int l = k - 1;
    while (l >= 0 && a[l] == a[k - 1]) --l;
    int r = k - 1;
    while (r < n && a[r] == a[k - 1]) ++r;
    std::cout << binom(r - 1- l, k - 1 - l) << "\n";
  }
  return 0;
}