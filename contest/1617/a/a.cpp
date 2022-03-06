#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  std::string a, b;
  std::cin >> a >> b;
  int c[26]{};
  for (auto x : a) ++c[x - 'a'];
  std::cout << std::string(c[0], 'a');
  if (b == "abc" && c[0]) {
    std::cout << std::string(c[2], 'c');
    std::cout << std::string(c[1], 'b');
  } else {
    std::cout << std::string(c[1], 'b');
    std::cout << std::string(c[2], 'c'); 
  }
  for (int i = 3; i < 26; ++i) {
    std::cout << std::string(c[i], 'a' + i);
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
