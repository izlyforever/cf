#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::string sa, sb;
  std::cin >> sa >> sb;
  std::vector<int> a(n + 2, -1), b(n + 2, -1);
  for (int i = 0; i < n; ++i) a[i + 1] = sa[i] - '0';
  for (int i = 0; i < n; ++i) b[i + 1] = sb[i] - '0';
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (b[i] == 1) {
      if (a[i - 1] == 1) {
        ++ans;
      } else if (a[i] == 0) {
        ++ans;
        a[i] = -1;
      } else if (a[i + 1] == 1) {
        ++ans;
        a[i + 1] = -1;
      }
    }
  }
  std::cout << ans << '\n';
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