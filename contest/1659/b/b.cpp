#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  std::vector<int> a(n);
  int kk = k;
  for (int i = 0; k > 0 && i < n; ++i) if ((kk & 1) ^ (s[i] == '0')) {
    --k;
    a[i] = 1;
  }
  a.back() += k;
  for (int i = 0; i < n; ++i) if ((kk - a[i]) & 1) {
    s[i] ^= 1;
  }
  std::cout << s << '\n';
  for (auto x : a) std::cout << x << ' ';
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
