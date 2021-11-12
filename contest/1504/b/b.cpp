#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  int n;
  std::string a, b;
  std::cin >> n >> a >> b;
  std::vector<int> c;
  int now = 0;
  for (auto x : a) {
    if (x == '0') --now;
    else ++now;
    c.emplace_back(now);
  }
  bool flag = true;
  while (n) {
    --n;
    if ((a[n] == b[n]) ^ flag) {
      if (c[n] != 0) return 0;
      flag = !flag;
    }
  }
  return 1;
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