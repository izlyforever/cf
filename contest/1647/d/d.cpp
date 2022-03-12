#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool isPrime(int x) {
  if (x <= 3) return true;
  if (x % 2 == 0) return false;
  for (int i = 3; i * i <= x; i += 2) if (x % i == 0) {
    return false;
  }
  return true;
}

int f(int x) {
  if (x % 2 == 0) return 2;
  for (int i = 3; i * i <= x; i += 2) if (x % i == 0) {
    return i;
  }
  return 0;
}

bool solve() {
  int n, d;
  std::cin >> n >> d;
  n /= d;
  if (n % d) return false;
  n /= d;
  int nn = n;
  if (isPrime(n)) return false;
  while (n % d == 0) n /= d;
  if (!isPrime(n)) return true;
  if (isPrime(d)) return false;
  int x = f(d);
  if (x * x != d || n != x) return true;
  return nn != x * d;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
