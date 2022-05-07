#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int k = std::count_if(a.begin(), a.end(), [](int x) {
    return x < 0;
  });
  for (int i = 0; i < k; ++i) a[i] = -abs(a[i]);
  for (int i = k; i < n; ++i) a[i] = abs(a[i]);
  std::cout << (std::is_sorted(a.begin(), a.end()) ? "YES" : "NO") << '\n';
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
