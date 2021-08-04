#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  bool flag = true;
  for (int i = 2; i < s.size(); ++i) {
    if (((s[i - 2] - 'A') + (s[i - 1] - 'A')) % 26 != (s[i] - 'A')) flag = false;
  }
  std::cout << (flag ? "YES" : "NO") << '\n';
  return 0;
}