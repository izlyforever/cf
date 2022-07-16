#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::string ans(n, '1');
  for (int i = n - 1, cur = 0; i >= 0; --i) {
    if (a[i] > cur) {
      if (cur < q) {
        ++cur;
      } else {
        ans[i] = '0';
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
