#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;
  std::map<int, int> ma, mb;
  for (int i = 0; i < n; ++i) ma[-a[i]] = i;
  for (int i = 0; i < n; ++i) mb[-b[i]] = i;
  std::string s(n, '0');
  std::queue<int> Q;
  Q.push(ma.begin()->second);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    s[u] = '1';
    while (!ma.empty() && a[u] < a[ma.begin()->second]) {
      Q.push(ma.begin()->second);
      ma.erase(ma.begin());
    }
    while (!mb.empty() && b[u] < b[mb.begin()->second]) {
      Q.push(mb.begin()->second);
      mb.erase(mb.begin());
    }
  }
  std::cout << s << '\n';
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
