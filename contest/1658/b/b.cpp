#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int N = 1e3 + 2;
const int M = 998244353;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  std::vector<int> fac(N);
  fac[0] = 1;
  for (int i = 1; i < N; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
  while (cas--) {
    int n;
    std::cin >> n;
    if (n % 2 == 1) {
      std::cout << "0\n";
    } else {
      std::cout << 1LL * fac[n / 2] * fac[n / 2] % M << '\n';
    }
  }
  return 0;
}
