#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int i = 0;
  while (i < n && s[i] == '?') ++i;
  if (i == n) {
    for (int i = 0; i < n; ++i) s[i] = (i & 1 ? 'R' : 'B');
  } else {
    int j = i - 1;
    char tmp = s[i];
    while (j >= 0) {
      s[j] = (tmp == 'R' ? 'B' : 'R');
      tmp = s[j];
      --j;
    }
    while (i < n) {
      while (i < n && s[i] != '?') ++i;
      char cur = s[i - 1];
      while (i < n && s[i] == '?') {
        s[i] = (cur == 'R' ? 'B' : 'R');
        cur = s[i];
        ++i;
      }
    }
  }
  std::cout << s << '\n';
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