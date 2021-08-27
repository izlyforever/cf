#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
std::string solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    if (std::string("14689").find(s[i]) != std::string::npos) return std::string(1, s[i]);
  }
  for (int i = 1; i < n; ++i) {
    if (std::string("25").find(s[i]) != std::string::npos) return std::string(1, s[0]) + std::string(1, s[i]);
  }
  for (char x = '1'; x <= '9'; ++x) {
    if (std::count(s.begin(), s.end(), x) > 1) return std::string(2, x);
  }
  for (auto it = s.begin(); it != s.end(); ++it) if (*it == '3') {
    s.erase(it);
    break;
  }
  if (s[0] == '2' || s[0] == '5') return {s.begin(), s.begin() + 2};
  return {s.begin(), s.begin() + 3};
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    auto s = solve();
    std::cout << s.size() << '\n' << s << '\n';
  }
  return 0;
}