#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  int l = 0, r = n - 1;
  std::vector<int> a, b;
  while (l < r) {
    while (l < r && s[l] == '0') ++l;
    while (l < r && s[r] == '1') --r;
    if (l != r) {
      a.emplace_back(l + 1);
      b.emplace_back(r + 1);
      ++l;
      --r;
    }
  }
  if (a.empty()) {
    std::cout << "0\n";
  } else {
    std::cout << "1\n";
    std::cout << a.size() * 2;
    for (auto &x : a) std::cout << ' ' << x;
    while (!b.empty()) {
      std::cout << ' ' << b.back();
      b.pop_back();
    }
    std::cout << '\n';
  }
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