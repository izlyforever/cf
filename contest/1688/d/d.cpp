#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::vector<LL> s(n + 1);
  for (int i = 0; i < n; ++i) s[i + 1] = a[i] + s[i];
  LL ans = 0;
  if (n >= k) {
    // 0, 1, 2, k - 1 = s[k] - s[0]
    // n - k, ..., n - 1 = s[n] - s[n - k]
    for (int i = k; i <= n; ++i) {
      ans = std::max(ans, s[i] - s[i - k]);
    }
    // 0 + 1 + ... + k - 1
    ans += 1LL * k * (k - 1) / 2;
  } else {
    ans += s.back();
    // k - 1 + k - 2 + ... + k - n
    ans += 1LL * (k - 1 + k - n) * n / 2;
  }
  std::cout << ans  << '\n';
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
