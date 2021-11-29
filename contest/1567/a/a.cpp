#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      std::cout << "LR";
      ++i;
    } else {
      std::cout << (s[i] == 'U' ? "D" : "U");
    }
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