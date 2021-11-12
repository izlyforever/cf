#include <bits/stdc++.h>
using LL = long long;

void solve() {
  int n, q;
  std::string s;
  std::cin >> n >> q >> s;
  std::vector<int> a{0};
  for (auto& x : s) a.emplace_back(a.back() + (x - 'a' + 1));
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << a[r] - a[l - 1] << '\n';
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}