#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 1e9 + 7;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    LL r = 1;
    std::vector<LL> a(n, 1);
    for (int i = 1; i < k; ++i) {
      r = (r + std::accumulate(a.begin(), a.end(), 0LL)) % M;
      std::vector<LL> b(n);
      if (i & 1) {
        for (int i = n - 2; i >= 0; --i) {
          b[i] = b[i + 1] + a[i + 1];
          if (b[i] >= M) b[i] -= M;
        }
      } else {
        for (int i = 1; i < n; ++i) {
          b[i] = b[i - 1] + a[i - 1];
          if (b[i] >= M) b[i] -= M;
        }
      }
      std::swap(a, b);
    }
    std::cout << r << '\n';
  }
  return 0;
}