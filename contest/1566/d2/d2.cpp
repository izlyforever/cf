#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

template <typename T>
std::vector<T> discrete(std::vector<T>& a) {
  auto r = a;
  std::sort(r.begin(), r.end());
  r.erase(std::unique(r.begin(), r.end()), r.end());
  for (auto& x : a) {
    x = std::lower_bound(r.begin(), r.end(), x) - r.begin();
  }
  return r;
}

template<typename T>
struct Bitree {
  std::vector<T> s_;
  Bitree() {}
  Bitree(int n) : s_(n + 1) {}
  int lowbit(int n) { return n & (-n); }
  void add(int id, T p) {
    int ns = s_.size();
    while (id < ns) {
      s_[id] += p;
      id += lowbit(id);
    }
  }
  T sum(int id) {
    T r = 0;
    while (id) {
      r += s_[id];
      id -= lowbit(id);
    }
    return r;
  }
  // find minimal index s.t. sum(id) >= x, sum must be increased
  int search(T val) {
    T sum = 0;
    int id = 0;
    for (int i = std::__lg(s_.size()); ~i; --i) {
      if (id + (1 << i) < (int)s_.size() && sum + s_[id + (1 << i)] < val) {
        id += (1 << i);
        sum += s_[id];
      }
    }
    return ++id;
  }
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  int nm = n * m;
  std::vector<std::pair<int, int>> a(nm);
  for (int i = 0, x; i < nm; ++i) {
    std::cin >> x;
    a[i] = {x, i};
  }
  std::sort(a.begin(), a.end());
  LL ans = 0;
  for (int i = 0; i < n; ++i) {
    std::vector<std::pair<int, int>> b(m);
    std::vector<int> c(m);
    for (int j = 0, t = i * m; j < m; ++j) {
      c[j] = a[t + j].second;
    }
    discrete(c);
    for (int j = 0, t = i * m; j < m; ++j) {
      b[j] = {a[t + j].first, -c[j]};
    }
    std::sort(b.begin(), b.end());
    std::vector<int> pos(m);
    for (int j = 0; j < m; ++j) pos[-b[j].second] = j + 1;
    Bitree<int> A(m);
    for (int j = 0; j < m; ++j) {
      ans += A.sum(pos[j]);
      A.add(pos[j], 1);
    }
  }
  std::cout << ans << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}