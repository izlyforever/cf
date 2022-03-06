#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool check(const std::string& s) {
  int i = 0, j = s.size() - 1;
  while (i <= j) {
    if (s[i] != s[j]) return false;
    ++i;
    --j;
  }
  return true;
}

int solve() {
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  return k == 0 || check(s) ? 1 : 2;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}
