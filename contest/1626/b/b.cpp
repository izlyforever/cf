#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.size();
  bool flag = true;
  for (int i = n - 1; i > 0; --i) {
    if ((s[i] - '0') + (s[i - 1] - '0') >= 10) {
      flag = false;
      s[i] = (s[i] - '0') + (s[i - 1] - '0') - 10 + '0';
      s[i - 1] = '1';
      break;
    }
  }
  if (flag) {
    s[1] += s[0] - '0';
    s.erase(s.begin());
  }
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