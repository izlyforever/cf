#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  std::vector<int> a{0}, b{0};
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'W') ++a.back();
    else a.emplace_back(a.back());
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'W') ++b.back();
    else b.emplace_back(b.back());
  }
  int ans = 0;
  for (int i = 0; i <= k && i < a.size(); ++i) {
    ans = std::max(ans, a[i] + (k - i > b.size() ? b.back() : b[k - i]));
  }
  std::cout << ans << '\n';
  return 0;
}
