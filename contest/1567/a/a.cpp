#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
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
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}