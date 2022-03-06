#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// Bit Tree Minimal version
template<typename T>
struct BitreeMin {
  std::vector<T> s_;
  BitreeMin() {}
  BitreeMin(int n) : s_(n + 1, std::numeric_limits<T>::max()) {}
  static int lowbit(int n) { return n & (-n); }
  void modify(int id, T p) {
    int ns = s_.size();
    while (id < ns) {
      s_[id] = std::min(s_[id], p);
      id += lowbit(id);
    }
  }
  // cal minimal value in [1, id]
  T min(int id) {
    T r = std::numeric_limits<T>::max();
    while (id) {
      r = std::min(r, s_[id]);
      id -= lowbit(id);
    }
    return r;
  }
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), w(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i] >> w[i];
  }
  std::vector<std::vector<std::pair<int, int>>> q(n);
  for (int i = 0; i < m; ++i) {
    int l, r;
    std::cin >> l >> r;
    --l; --r;
    q[l].emplace_back(r, i);
  }
  std::vector<int> l(n, -1), r(n, -1);
  {
    std::stack<int> Q;
    for (int i = 0; i < n; ++i) {
      while (!Q.empty() && w[Q.top()] > w[i]) Q.pop();
      if (!Q.empty()) l[i] = Q.top();
      Q.push(i);
    }
  }
  {
    std::stack<int> Q;
    for (int i = n - 1; i >= 0; --i) {
      while (!Q.empty() && w[Q.top()] > w[i]) Q.pop();
      if (!Q.empty()) r[i] = Q.top();
      Q.push(i);
    }
  }
  std::vector<std::vector<int>> p(n);
  for (int i = 0; i < n; ++i) {
    if (l[i] != -1) p[l[i]].emplace_back(i);
  }
  for (int i = 0; i < n; ++i) {
    if (r[i] != -1) p[i].emplace_back(r[i]);
  }
  std::vector<LL> ans(m);
  BitreeMin<LL> A(n);
  for (int i = n - 1; i >= 0; --i) {
    for (auto x : p[i]) {
      A.modify(x + 1, 1LL * (a[x] - a[i]) * (w[x] + w[i]));
    }
    for (auto [x, id] : q[i]) {
      ans[id] = A.min(x + 1);
    }
  }
  for (auto x : ans) std::cout << x << '\n';
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
