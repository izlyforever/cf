#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;

int main() {
  //freopen("in","r",stdin);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(m);
  for (auto &x : a) std::cin >> x;
  for (auto &x : b) std::cin >> x;

  auto f = [&](int ma) {
    LL r = 0;
    for (auto x : a) if (x < ma) r += ma - x;
    for (auto x : b) if (x > ma) r += x - ma;
    return r;
  };
  // for a given covex function f: (f(a) + f(b)) / 2 >= f((a + b) / 2)
  auto tupleCut = [&](int l, int r) {
    const double phiL = (3 - std::sqrt(5)) / 2;
    const double phiR = (std::sqrt(5) - 1) / 2;
    auto getLeft = [&](int l, int r) -> int {
      return l + (r - l) * phiL;
    };
    auto getRight = [&](int l, int r) -> int {
      return l + (r - l) * phiR;
    };
    int lm = getLeft(l, r), rm = getRight(l, r);
    LL fl = f(lm), fr = f(rm);
    while (r - l > 2) {
      if (fl < fr) {
        r = rm;
        rm = lm;
        fr = fl;
        fl = f(lm = getRight(l, rm));
      } else {
        l = lm;
        lm = rm;
        fl = fr;
        fr = f(rm = getLeft(lm, r));
      }
    }
    fl = f(l), fr = f(r);
    while (l < r) {
      if (fl < fr) fr = f(--r);
      else fl = f(++l);
    }
    return fr;
  };
  print(tupleCut(1, 1e9));
  return 0;
}