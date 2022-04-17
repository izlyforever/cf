#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, r, b;
  std::cin >> n >> r >> b;
  std::string s(n, 'R');
  int d = n / (b + 1) + 1;
  for (int i = d - 1; i < n; i += d, --b) s[i] = 'B';
  assert(b >= 0);
  for (int i = 0; b; i += d) {
    --b;
    s[i] = 'B';
  }
  assert(b == 0);
  std::cout << s << '\n';
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
