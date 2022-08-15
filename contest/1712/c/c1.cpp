#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::map<int, int> l;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    if (!l.count(a[i])) l[a[i]] = i;
  }
  int mx = INT_MAX;
  for (int i = n; i > 0; --i) {
    if (a[i] >= mx) break;
    mx = a[i];
    int t = l[a[i]];
    while (i > t && a[i] == a[t]) --i;
    if (i > t) break;
    l.erase(a[i]);
  }
  std::cout << l.size() << '\n';
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
