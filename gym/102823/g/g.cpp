#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  int r = 0;
  for (int i = 1; i < n; ++i) {
    r = std::gcd(r, a[i] - a[i - 1]);
  }
  if (r == 1) return -1;
  if (r == 0) return a[0] == 1;
  if (std::gcd(r, a[0]) > 1) return 0;
  int t = a[0] % r;
  int ans = r - t;
  for (int i = 2; i * i <= r; ++i) {
    if (r % i == 0) {
      ans = std::min(ans, i - t % i);
      while (r % i == 0) r /= i;
    }
  }
  return ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  for (int T = 1; T <= cas; ++T) {
    std::cout << "Case " << T << ": " << solve() << "\n";
  }
  return 0;
}
