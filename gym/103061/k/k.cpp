#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int M = 998244353;
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> inv(n + 1), a(n + 1);
  inv[1] = a[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = 1LL * (M - M / i) * inv[M % i] % M;
    a[i] = (a[i - 1] + inv[i]) % M;
  }
  std::vector<int> p(n + 1);
  std::iota(p.begin(), p.end(), 0);
  std::function<int(int)> find = [&](int x) -> int {
    return p[x] == x ? x : p[x] = find(p[x]);
  };
  std::cout << (n + M - a[n]) % M << '\n';
  for (int i = 1, cur = 0, x; i <= n; ++i) {
    std::cin >> x;
    if (find(i) == find(x)) ++cur;
    else p[p[i]] = p[x];
    std::cout << (n - cur + M - a[n - i]) % M << '\n';
  }
  return 0;
}
