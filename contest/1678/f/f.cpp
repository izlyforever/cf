#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int M = 998244353;

int solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  for (int i = 1; i <= k; ++i) if (a[n - i] > 0) return 0;
  int ans = 1;
  for (int i = 1; i <= k; ++i) ans = 1LL * ans * i % M;
  for (int i = k; i < n; ++i) {
    if (a[i - k] == -1) {
      ans = 1LL * ans * (i + 1) % M;
    } else if (a[i - k] == 0) {
      ans = 1LL * ans * (k + 1) % M;
    }
  }
  return ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}
