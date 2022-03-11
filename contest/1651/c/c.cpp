#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

LL f(std::vector<LL> a, std::vector<LL> b) {
  LL ans = abs(a[0] - b[0]);
  int ax = a.back(), bx = b.back();
  {
    LL tmp = INT64_MAX;
    for (auto x : b) {
      tmp = std::min(tmp, abs(x - ax));
    }
    ans += tmp;
  }
  {
    LL tmp = INT64_MAX;
    for (auto x : a) {
      tmp = std::min(tmp, abs(x -bx));
    }
    ans += tmp;
  }
  return ans;
}

LL g(std::vector<LL> a, std::vector<LL> b) {
  std::vector<LL> aa{a[0], a.back()}, bb{b[0], b.back()};
  LL ans = 0;
  for (auto ax : aa) {
    LL tmp = INT64_MAX;
    for (auto x : b) {
      tmp = std::min(tmp, abs(x - ax));
    }
    ans += tmp;
  }
  for (auto bx : bb) {
    LL tmp = INT64_MAX;
    for (auto x : a) {
      tmp = std::min(tmp, abs(x -bx));
    }
    ans += tmp;
  }
  ans = std::min(ans, abs(a[0] - b[0]) + abs(a.back() - b.back()));
  ans = std::min(ans, abs(a[0] - b.back()) + abs(a.back() - b[0]));
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<LL> a(n), b(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;
  LL ans = g(a, b);
  ans = std::min(ans, f(a, b));
  std::reverse(a.begin(), a.end());
  ans = std::min(ans, f(a, b));
  std::reverse(b.begin(), b.end());
  ans = std::min(ans, f(a, b));
  std::reverse(a.begin(), a.end());
  ans = std::min(ans, f(a, b));
  std::cout << ans << '\n';
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
