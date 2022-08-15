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
  T sum(int l, int r) { return sum(r) - sum(l - 1); }
};

// 2k = lcm(i, j, k) ==> k < i + j
// j = 2k / 3
// 2k / 3 > i > 2k / 6, factor of 2 * k;
// Thus i = 2k / 4, 2k / 5
// thus l <= k <= r, 6 | k or 15 | k note that l <= i
// 2k / 5 >= l, k >= 5 * l / 2

const int N = 2e5 + 2;

LL C3(int x) {
  return 1LL * x * (x - 1) * (x - 2) / 6;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  std::cin >> n;
  std::vector<LL> ans(n);
  std::vector<std::array<int, 3>> a(n);
  for (int i = 0; i < n; ++i) {
    int l, r;
    std::cin >> l >> r;
    --l;
    ans[i] = C3(r - l);
    ans[i] -= std::max(0, r / 6 - l / 3);
    ans[i] -= std::max(0, r / 15 - l / 6);
    a[i] = {l, r, i};
  }
  std::sort(a.begin(), a.end(), [&](auto x, auto y) {
    return x[0] > y[0];
  });
  std::vector<int> cnt(N);
  Bitree<LL> A(N);
  int now = N - 1;
  for (auto [l, r, i] : a) {
    while (now > l) {
      for (int j = now * 2; j < N; j += now) {
        A.add(j, cnt[j]++);
      }
      --now;
    }
    ans[i] -= A.sum(r);
  }
  for (auto &x : ans) std::cout << x << '\n';
  return 0;
}
