
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// longest non-decreasing subsquence, return choosen index
template<typename T>
auto LISP(const std::vector<T>& a, T val) {
  int n = a.size();
  std::vector<T> b;
  b.reserve(n);
  // p[i] means the preview number of choosen i
  std::vector<int> p(n);
  std::iota(p.begin(), p.end(), 0);
  // q[i] means current b[i] is a[q[i]]
  std::vector<int> q;
  q.reserve(n);
  for (int i = 0; i < n; ++i) {
    auto it = std::upper_bound(b.begin(), b.end(), a[i]);
    if (it == b.end()) {
      if (!q.empty()) p[i] = q.back();
      b.emplace_back(a[i]);
      q.emplace_back(i);
    } else {
      *it = a[i];
      auto t = it - b.begin();
      q[t] = i;
      if (t > 0) p[i] = q[t - 1];
    }
  }
  std::stack<int> c;
  int now = q.back();
  c.push(now);
  while (now != p[now]) {
    now = p[now];
    c.push(now);
  }
  return c;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<LL> a(n);
  for (auto &x : a) std::cin >> x;
  if (is_sorted(a.begin(), a.end())) {
    std::cout << 0 << '\n';
    return;
  }
  if (a[n - 1] < a[n - 2] || a[n - 1] < 0) {
    std::cout << -1 << '\n';
    return;
  }
  std::reverse(a.begin(), a.end());
  for (auto &x : a) x = -x;
  int c = 0, cc = 1;
  {
    for (int i = 1; a[i - 1] <= a[i] && a[i] <= 0; ++i) {
      if (a[i] - a[i - 1] < a[cc] - a[cc - 1]) {
        cc = i;
      }
      c = i;
    }
  }
  auto printAns = [&](std::stack<int>& s) {

  };
  if (c > 0) {
    int nc = c;
    a[c + 1] = a[cc] - a[cc - 1];
    if (a[c + 1] == 0) nc = c + 1;
    auto ans2 = LISP(std::vector<LL>(a.begin() + c, a.end()), -a[nc]);
    if (a[c - 1] > a[c]) {
      std::cout << ans2.size() + 1 << '\n';
      std::cout << n - c - 1 << ' ' << n - cc << ' ' << n - cc + 1 << '\n';
      printAns(ans2);
    } else {
      auto ans = LISP(std::vector<LL>(a.begin() + c, a.end()), -a[c]);
      if (ans2.size() < ans.size()) {
        std::cout << ans2.size() + 1 << '\n';
        std::cout << n - c - 1 << ' ' << n - cc << ' ' << n - cc + 1 << '\n';
        printAns(ans2);
      } else {
        std::cout << n - c - ans.size() << '\n';
        printAns(ans);
      }
    }
  } else {
    auto ans = LISP(std::vector<LL>(a.begin() + c, a.end()), -a[c]);
    std::cout << n - c - ans.size() << '\n';
    printAns(ans);
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