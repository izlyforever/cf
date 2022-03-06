#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::set<int> S;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (S.count(x)) S.insert(-x);
    else S.insert(x);
  }
  std::cout << S.size() << '\n';
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
