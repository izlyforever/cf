#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), ans(n);
  for (auto &x : a) {
    std::cin >> x;
    --x;
  }
  if (n == 1) {
    std::cout << -1 << '\n';
    return;
  }
  std::set<int> S;
  for (int i = 0; i < n; ++i) S.insert(i);
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] != *S.begin()) {
      ans[i] = *S.begin();
      S.erase(S.begin());
    } else {
      S.erase(S.begin());
      ans[i] = *S.begin();
      S.erase(*S.begin());
      S.insert(a[i]);
    }
  }
  ans[n - 1] = *S.begin();
  if (ans[n - 1] == a[n - 1]) std::swap(ans[n - 1], ans[n - 2]);
  for (int i = 0; i < n; ++i) {
    std::cout << ans[i] + 1 << ' ';
  }
  std::cout << '\n';
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
