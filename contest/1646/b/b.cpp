#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  int l = 1, r = n - 1;
  LL sl = a[0], sr = 0;
  while (l < r) {
    sl += a[l];
    sr += a[r];
    if (sl < sr) {
      std::cout << "YES\n";
      return;
    }
    ++l;
    --r;
  }
  std::cout << "NO\n";
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