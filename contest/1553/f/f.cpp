#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

template<typename T>
struct Bitree {
  std::vector<T> s;
  Bitree() {}
  Bitree(int n) : s(n + 1) {}
  int lowbit(int n) { return n & (-n); }
  void add(int id, T p) {
    int ns = s.size();
    while (id < ns) {
      s[id] += p;
      id += lowbit(id);
    }
  }
  T sum(int id) {
    T r = 0;
    while (id) {
      r += s[id];
      id -= lowbit(id);
    }
    return r;
  }
};
const int N = 3e5 + 2;
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  Bitree<LL> A(N), B(N);
  LL ans = 0, sumA = 0;
  for (int i = 0; i < n; ++i) {
    ans += 1LL * a[i] * i;
    ans -= A.sum(a[i]);
    for (int j = a[i]; j < N; j += a[i]) A.add(j, a[i]);
    ans += sumA;
    LL tmp = 0;
    for (int j = a[i]; j < N; j += a[i]) {
      tmp += (B.sum(N) - B.sum(j - 1));
    }
    ans -= tmp * a[i];
    B.add(a[i], 1);
    sumA += a[i];
    std::cout << ans << " \n"[i == n - 1];
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