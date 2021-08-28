#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> b(n), a(2 * n - 1);
  for (auto &x : b) std::cin >> x;
  a[0] = b[0];
  std::stack<int> l, r;
  for (int i = 1; i < n; ++i) {
    if (b[i] == b[i - 1]) {
      a[i * 2 - 1] = INT_MIN;
      a[i * 2] = INT_MAX;
    } else if (b[i] > b[i - 1]) {
      if (!r.empty() && b[i] > r.top()) return false;
      a[i * 2 - 1] = INT_MAX;
      if (!r.empty() && b[i] == r.top()) {
        r.pop();
        a[i * 2] = INT_MAX;
      } else {
        a[i * 2] = b[i];
      }
      if (l.empty() || l.top() != b[i - 1]) l.push(b[i - 1]);
    } else {
      if (!l.empty() && b[i] < l.top()) return false;
      a[i * 2 - 1] = INT_MIN;
      if (!l.empty() && b[i] == l.top()) {
        l.pop();
        a[i * 2] = INT_MIN;
      } else {
        a[i * 2] = b[i];
      }
      if (r.empty() || r.top() != b[i - 1]) r.push(b[i - 1]);
    }
  }
  for (auto x : a) std::clog << x << ' ';
  std::clog << '\n';
  return true;
}


int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}