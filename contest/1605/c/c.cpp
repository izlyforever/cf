#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int x = 0;
  while (x < n && s[x] != 'a') ++x;
  for (int i = x + 1; i < n; ++i) {
    if (s[i] == 'a' && s[i - 1] == 'a') return 2;
  }
  for (int i = x + 1; i < n; ++i) {
    if (s[i] == 'a' && s[i - 2] == 'a') return 3;
  }
  int lastA = x;
  for (int i = x + 1; i < n; ++i) {
    if (s[i] == 'a') {
      if (i - lastA == 3 && s[i - 1] != s[i - 2]) return 4;
      lastA = i;
    }
  }
  lastA = x;
  for (int i = x + 1; i < n; ++i) {
    if (s[i] == 'a') {
      if (i - lastA == 3 && i >= 6 && s[i - 6] == 'a' && s[i - 1] != s[i - 4]) return 7;
      lastA = i;
    }
  }
  return -1;
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
