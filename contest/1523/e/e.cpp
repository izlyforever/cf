#include <bits/stdc++.h>
using LL = long long;


int powMod(int x, int n, int p) {
  int r = 1;
  while (n) {
    if (n&1) r = 1LL * r * x % p;
    n >>= 1; x = 1LL * x * x % p;
  }
  return r;
}

// 一般情况下 N < 1e6, M 必须是一个小于 INT_MAX 的素数
namespace Binom {
const int CN = 65; // 再大就超 LL 了
LL C[CN][CN];
void initC() {
  for (int i = 0; i < CN; ++i) C[i][0] = C[i][i] = 1;
  for (int i = 1; i < CN; ++i) {
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
}
int N = 0, M = 1e9 + 7;
std::vector<int> fac, ifac;
void setMod(int m) {
  M = m;
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
  ifac[N - 1] = powMod(fac[N - 1], M - 2, M);
  for (int i = N - 1; i; --i) ifac[i - 1] = 1LL * ifac[i] * i % M;
}
// 请确保 n < m，否则无法保证后面的正确性
void init(int n, int m = M) {
  N = n;
  fac.resize(N);
  ifac.resize(N);
  setMod(m);
  initC();
}
// 需要预处理小于 n 的所有值！
int binom(int n, int k) {
  if (n < 0 || n < k) return 0;
  return 1LL * fac[n] * ifac[k] % M * ifac[n - k] % M;
}
// 一般说来需要预处理出小于 M 的所有值，且 M 是素数！
int lucas(int n, int k) {
  int r = 1;
  while (n && k) {
    int np = n % M, kp = k % M;
    if (np < kp) return 0;
    r = 1LL * r * binom(np, kp) % M;
    n /= M; k /= M;
  }
  return r;
}
} // namespace Binom
// 模板例题：https://www.luogu.com.cn/problem/P3807

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  Binom::init(1e5 + 2);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    int ans = 1;
    for (int p = 0; p * k < n; ++p) {
      int t = powMod(Binom::binom(n, p + 1), Binom::M - 2, Binom::M);
      ans = (ans + 1LL * Binom::binom(n - (k - 1) * p, p + 1) * t) % Binom::M;
    }
    std::cout << ans << '\n';
  }
  return 0;
}
