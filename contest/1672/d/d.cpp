#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;
  std::multiset<int> S;
  for (int j = 0, i = 0; j < n; ++j) {
    if (i < n && a[i] == b[j]) {
      ++i;
      continue;
    }
    if (j > 0 && b[j] == b[j - 1] && S.count(b[j])) {
      S.erase(S.find(b[j]));
      continue;
    }
    while (i < n && a[i] != b[j]) {
      S.insert(a[i]);
      ++i;
    }
    if (i == n) return false;
    ++i;
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
