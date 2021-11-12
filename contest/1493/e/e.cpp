#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// 这规律也太难找了吧
std::string add(std::string s) {
  int i = s.size() - 1;
  while (s[i] == '1') {
    s[i] = '0';
    --i;
  }
  s[i] = '1';
  return s;
}

std::string solve() {
  int n;
  std::cin >> n;
  std::string a, b;
  std::cin >> a >> b;
  if (a == b) return a;
  if (a[0] != b[0]) return std::string(n, '1');
  if (add(a) == b || b.back() == '1') return b;
  return add(b);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << solve() << "\n";
  return 0;
}