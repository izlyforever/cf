#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::deque<int> Q{a[0]};
  for (int i = 1; i < n; ++i) {
    if (a[i] < Q.front()) {
      Q.push_front(a[i]);
    } else {
      Q.push_back(a[i]);
    }
  }
  for (auto x : Q) std::cout << x << ' ';
  std::cout << '\n';
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