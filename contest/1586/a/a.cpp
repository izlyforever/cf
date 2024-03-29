#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool isPrime(int n) {
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int s = std::accumulate(a.begin(), a.end(), 0);
  if (!isPrime(s)) {
    std::cout << n << '\n';
    for (int i = 1; i <= n; ++i) std::cout << i << " \n"[i == n];
  } else {
    std::cout << n - 1 << '\n';
    int it = 0;
    while (a[it] % 2 == 0) ++it;
    ++it;
    for (int i = 1; i <= n; ++i) if (i != it) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
