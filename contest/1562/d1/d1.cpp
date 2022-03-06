#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, q;
  std::string s;
  std::cin >> n >> q >> s;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = a[i - 1] + (s[i - 1] == '+' ^ (i & 1)  ? 1 : -1);
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    if (a[l - 1] == a[r]) std::cout << "0\n";
    else std::cout << ((r - l) % 2 ? 2 : 1) << '\n';
  }
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
