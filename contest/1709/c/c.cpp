#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  std::string s;
  std::cin >> s;
  int n = s.size();
  assert(n % 2 == 0);
  int leftB = n / 2 - std::count(s.begin(), s.end(), '(');
  int now = 0;
  while (now < n) {
    if (s[now] == '?') {
      s[now] = '(';
      --leftB;
      if (leftB == 0) break;
    }
    ++now;
  }
  if (now == n) return true;
  int cur = now + 1;
  while (cur < n && s[cur] != '?') ++cur;
  if (cur == n) return true;
  s[now] = ')';
  for (int i = 0, sm = 0; i < cur; ++i) {
    if (s[i] == '(') ++sm;
    else --sm;
    if (sm < 0) return true;
  }
  return false;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
