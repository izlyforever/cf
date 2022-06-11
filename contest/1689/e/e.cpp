#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class DSU {
  std::vector<int> p;
 public:
  DSU(int n) : p(n) {
    std::iota(p.begin(), p.end(), 0);
  }
  int find(int x) {
    assert(x >= 0 && x < p.size());
    return x == p[x] ? x : p[x] = find(p[x]);
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  void merge(int x, int y) {
    p[find(x)] = find(y);
  }
};

constexpr int BIT = 30;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  auto check = [&]() {
    DSU A(BIT);
    std::vector<int> use(BIT);
    int mn = BIT;
    for (auto x : a) {
      if (x == 0) return false;
      const int tx = __builtin_ctz(x);
      for (int i = tx; i < BIT; ++i) {
        if (x & (1 << i)) {
          use[i] = 1;
          A.merge(i, tx);
        }
      }
      mn = std::min(mn, tx);
    }
    if (mn == BIT) return true;
    int rt = A.find(mn);
    for (int i = mn + 1; i < BIT; ++i) if (use[i]) {
      if (A.find(i) != rt) return false;
    }
    return true;
  };
  int ans = 0;
  for (auto &x : a) if (x == 0) {
    ++x;
    ++ans;
  }
  auto printAns = [&]() {
    std::cout << ans << '\n';
    for (auto x : a) std::cout << x << ' ';
    std::cout << '\n';
  };

  if (check()) {
    printAns();
    return;
  }
  ++ans;
  for (int i = 0; i < n; ++i) {
    ++a[i];
    if (check()) {
      printAns();
      return;
    }
    --a[i];
  }
  for (int i = 0; i < n; ++i) {
    --a[i];
    if (check()) {
      printAns();
      return;
    }
    ++a[i];
  }
  ++ans;
  int mx = 0;
  for (auto x : a) mx = std::max(mx, __builtin_ctz(x));
  for (int i = 0, flag = 0; i < n; ++i) {
    if (__builtin_ctz(a[i]) == mx) {
      if (flag) {
        ++a[i];
        printAns();
        return;
      } else {
        --a[i];
        ++flag;
      }
    }
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
