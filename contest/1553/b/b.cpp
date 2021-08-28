#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
bool solve() {
  std::string s, t;
  std::cin >> s >> t;
  int n = s.size(), m = t.size();
  auto check = [&](int i) -> bool {
    for (int j = 1; j <= i && i + j < m; ++j) if (t[i + j] != t[i - j]) return false;
    return true;
  };
  for (int i = 0; i < m; ++i) if (check(i)) {
    std::string tmp(1, t[i]);
    for (int j = 1; j <= i || i + j < m; ++j) {
      if (j <= i) tmp += t[i - j];
      else tmp += t[i + j];
    }
    std::reverse(tmp.begin(), tmp.end());
    for (int j = 0; j < n; ++j) if (s[j] == tmp[0]) {
      if (s.substr(j, tmp.size()) == tmp) return true;
    }
  }
  return false;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}