#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

const int M = 1000000009;
int powMod(int x, int n) {
  int r = 1;
  while (n) {
    if (n&1) r = 1LL * r * x % M;
    n >>= 1; x = 1LL * x * x % M;
  }
  return r;
}

template<typename T>
std::tuple<T, T, T> exGcd(T a, T b) {
  if (b == 0) return {a, 1, 0};
  auto [d, y, x] = exGcd(b, a % b);
  return {d, x, y - a / b * x};
}
int main() {
  auto [d, x, y] = exGcd(1LL << 32, 1LL * M);
  std::cout << d << ' ' << x << ' ' << y << '\n';
  cerr((x << 32) + M * y);
  cerr((1LL << 32) % M);
  cerr(powMod(2, 32LL * (M - 2) % (M - 1)));
  return 0;
}