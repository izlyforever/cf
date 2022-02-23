#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::iota(a.begin(), a.end(), 0);
  auto check = [&]() -> bool {
    for (int i = 2; i < n; ++i) {
      if (n - a[i] == n - a[i - 1] + n - a[i - 2]) return false;
    }
    return true;
  };
  int ans = 0;
  do {
    if (check()) {
      ++ans;
      for (int i = 0; i < n; ++i) std::cout << n - a[i] << ' ';
      std::cout << '\n';
    }
    if (ans == n) break;
  } while (std::next_permutation(a.begin(), a.end()));
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