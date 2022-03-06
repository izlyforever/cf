#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

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
  std::vector<std::pair<int, int>> a(n * m);
  for (int i = 0, x; i < m; ++i) {
    std::cin >> x;
    a[i] = {x, -i};
  }
  std::sort(a.begin(), a.end());
  std::vector<int> pos(m);
  for (int i = 0; i < m; ++i) pos[-a[i].second] = i + 1;
  Bitree<int> A(m);
  LL ans = 0;
  for (int i = 0; i < m; ++i) {
    ans += A.sum(pos[i]);
    A.add(pos[i], 1);
  }
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
