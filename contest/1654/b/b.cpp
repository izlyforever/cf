#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  std::string s;
  std::cin >> s;
  int n = s.size();
  std::vector<int> a(26, n);
  int cur = n;
  for (int i = n - 1; i >= 0; --i) {
    if (a[s[i] - 'a'] == n) {
      a[s[i] - 'a'] = i;
      cur = i;
    }
  }
  std::cout << s.substr(cur) << '\n';
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
