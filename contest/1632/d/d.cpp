#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void merge(std::set<int>& a, std::set<int>& b) {
  if (a.size() < b.size()) {
    std::swap(a, b);
  }
  a.merge(b);
}

void solve() {
  int n;
  std::cin >> n;
  std::map<int, std::set<int>> gcd;
  auto check = [&](int i) {
    for (auto &[x, S] : gcd) {
      if (S.count(i - x)) return true;
    }
    return false;
  };
  for (int i = 0, ans = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    std::map<int, std::set<int>> gcdNew;
    for (auto it = gcd.begin(); it != gcd.end(); ++it) {
      merge(gcdNew[std::gcd(x, it->first)], it->second);
    }
    std::swap(gcdNew, gcd);
    gcd[x].emplace(i);
    if (check(i + 1)) {
      ++ans;
      gcd.clear();
    }
    std::cout << ans << ' ';
  }
  std::cout << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}