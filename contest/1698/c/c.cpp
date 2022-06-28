#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  std::vector<LL> a(n);
  for (auto &x : a) std::cin >> x;
  if (std::count_if(a.begin(), a.end(), [](LL x) {
    return x < 0;
  }) > 2) {
    return false;
  }
  if (std::count_if(a.begin(), a.end(), [](LL x) {
    return x > 0;
  }) > 2) {
    return false;
  }
  int n0 = std::count(a.begin(), a.end(), 0);
  std::vector<LL> b;
  for (auto x : a) if (x != 0) b.emplace_back(x);
  for (int i = 0; i < n0 && i < 3; ++i) b.emplace_back(0);
  int m = b.size();
  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      for (int k = j + 1; k < m; ++k) {
        if (!std::count(b.begin(), b.end(), b[i] + b[j] + b[k])) return false;
      }
    }
  }
  return true;
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
