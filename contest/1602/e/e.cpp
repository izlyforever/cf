
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
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
};

LL inverseOrderCount(std::vector<int> a) {
  discrete(a);
  Bitree<int> A(*std::max_element(a.begin(), a.end()) + 1);
  LL ans = 0;
  for (int i = a.size() - 1; i >= 0; --i) {
    ans += A.sum(a[i]);
    A.add(a[i] + 1, 1);
  }
  return ans;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(m);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;
  std::sort(b.begin(), b.end());
  std::vector<int> pos(m); // 0 <= pos[i] <= n
  std::function<void(int, int, int, int)> divConquer = [&](int p, int q, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2, len = q - p + 1;
    { // 提前析构，释放内存
      int bm = b[m];
      std::vector<int> pre(len), suf(len);
      for (int i = p; i < q; ++i) {
        pre[i - p + 1] = pre[i - p] + (a[i] > bm);
      }
      for (int i = q - 1; i >= p; --i) {
        suf[i - p] = suf[i - p + 1] + (a[i] < bm);
      }
      for (int i = 0; i < len; ++i) pre[i] += suf[i];
      int x = std::min_element(pre.begin(), pre.end()) - pre.begin();
      pos[m] = p + x;
    }
    divConquer(p, pos[m], l, m);
    divConquer(pos[m], q, m + 1, r);
  };
  divConquer(0, n, 0, m);
  std::vector<int> c;
  c.reserve(m + n);
  for (int i = 0, j = 0; i <= n; ++i) {
    while (j < m && pos[j] == i) {
      c.emplace_back(b[j]);
      ++j;
    }
    if (i < n) c.emplace_back(a[i]);
  }
  std::cout << inverseOrderCount(std::move(c)) << '\n';
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
