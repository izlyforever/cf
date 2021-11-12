#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  auto f = [](char x) {
    if (x == 'U') return 0;
    if (x == 'D') return 1;
    if (x == 'R') return 2;
    return 3;
  };
  int x, y;
  std::cin >> x >> y;
  std::string s;
  std::cin >> s;
  int cnt[4]{};
  for (auto c : s) ++cnt[f(c)];
  if (x >= 0) {
    if (cnt[2] < x) return false;
  } else {
    if (cnt[3] < -x) return false;
  }
  if (y >= 0) {
    if (cnt[0] < y) return false;
  } else {
    if (cnt[1] < -y) return false;
  }
  return true;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES\n" : "NO\n");
  }
  return 0;
}