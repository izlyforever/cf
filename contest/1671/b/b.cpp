#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int cnt[4]{};
  for (int i = 1; i < n; ++i) {
    int t = a[i] - a[i - 1];
    if (t >= 4) {
      std::cout << "NO\n";
      return;
    }
    ++cnt[t];
  }
  if (cnt[3] > 1 || (cnt[3] == 1 && cnt[2] > 0) || (cnt[2] > 2)) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
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
