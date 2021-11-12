#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> x(n), y(n), lx(n), ly(n), rx(n), ry(n);
  for (int i = 0; i < n; ++i) std::cin >> x[i] >> y[i];
  auto getlx = [&](int l, int r) {
    int now = INT_MAX;
    for (int i = r - 1; i >= l; --i) {
      now = std::min(now, x[i]);
      lx[i] = now;
    }
  };
  auto getly = [&](int l, int r) {
    int now = INT_MAX;
    for (int i = r - 1; i >= l; --i) {
      now = std::min(now, y[i]);
      ly[i] = now;
    }
  };
  auto getrx = [&](int l, int r) {
    int now = INT_MAX;
    for (int i = l; i < r; ++i) {
      now = std::min(now, x[i]);
      rx[i] = now;
    }
  };
  auto getry = [&](int l, int r) {
    int now = INT_MAX;
    for (int i = l; i < r; ++i) {
      now = std::min(now, y[i]);
      ry[i] = now;
    }
  };
  auto get = [&](int l, int r) {
    int m = (l + r) / 2;
    getlx(l, m);
    // getly(l, m);
    // getrx(m, r);
    // getry(m, r);
    std::thread thly(getly, l, m);
    std::thread thrx(getrx, m, r);
    std::thread thry(getry, m, r);
    thly.join();
    thrx.join();
    thry.join();
  };
  LL ans = 0;
  std::function<void(int, int)> divConqer = [&](int l, int r) {
    if (r - l == 1) {
      ans = std::max(ans, 1LL * x[l] * y[l]);
    } else {
      int m = (l + r) / 2;
      divConqer(l, m);
      divConqer(m, r);
      // 可以拆分成四个，然后它们并行
      get(l, r);
      // 这一部分可以被自动向量化
      for (int i = l; i < m; ++i) {
        for (int j = m; j < r; ++j) {
          ans = std::max(ans, 1LL * (j - i + 1) * (lx[i] < rx[j] ? lx[i] : rx[j]) * (ly[i] < ry[j] ? ly[i] : ry[j]));
        }
      }
    }
  };
  divConqer(0, n);
  std::cout << ans << '\n';
  return 0;
}