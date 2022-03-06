#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int N = 60;
const LL M = 1e9 + 7;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<LL> a(n);
    for (auto& x : a) std::cin >> x;
    int b[N]{};
    for (int i = 0; i < N; ++i) {
      for (auto& x : a) if ((x >> i) & 1) ++b[i];
    }
    LL r = 0;
    for (int i = 0; i < n; ++i) {
      LL r1 = 0;
      for (int j = 0; j < N; ++j) {
        if ((a[i] >> j) & 1) {
          (r1 += (1ll << j) % M * b[j]) %= M;
        }
      }
      LL r2 = 0;
      for (int j = 0; j < N; ++j) {
        if ((a[i] >> j) & 1) {
          (r2 += (1ll << j) % M * n) %= M;
        } else {
          (r2 += (1ll << j) % M * b[j]) %= M;
        }
      }
      (r += r1 * r2) %= M;
    }
    std::cout << r << std::endl;
  }
  return 0;
}
