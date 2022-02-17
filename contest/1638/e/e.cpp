#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

template<typename T>
struct Bitree {
  std::vector<T> s_;
  Bitree() {}
  Bitree(int n) : s_(n + 1) {}
  static int lowbit(int n) { return n & (-n); }
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
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<LL> add(n + 1);
  std::map<int, int> mp{{1, 1}};
  auto split = [&](int x) {
    auto it = std::prev(mp.upper_bound(x));
    mp[x] = it->second;
  };
  Bitree<LL> A(n + 1);
  auto rangeAdd = [&](int l, int r, LL val) {
    A.add(l, val);
    A.add(r, -val);
  };
  while (m--) {
    std::string op;
    std::cin >> op;
    if (op[0] == 'C') {
      int l, r, c;
      std::cin >> l >> r >> c;
      split(l);
      split(++r);
      auto it = mp.find(l);
      while (it->first != r) {
        rangeAdd(it->first, std::next(it)->first, add[it->second] - add[c]);
        it = mp.erase(it);
      }
      mp[l] = c;
    } else if (op[0] == 'A') {
      int c, x;
      std::cin >> c >> x;
      add[c] += x;
    } else {
      int i;
      std::cin >> i;
      auto it = std::prev(mp.upper_bound(i));
      std::cout << A.sum(i) + add[it->second] << '\n';
    }
  }
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