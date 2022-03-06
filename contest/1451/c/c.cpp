#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  int n, k;
  std::string a, b;
  std::cin >> n >> k >> a >> b;
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  // for (int i = 0; i < n; ++i) if (a[i] > b[i]) return 0;
  int sa = 0, sb = 0, t = 0;
  auto deal = [&](char c) {
    for (int i = 1; i <= k; ++i) a[sa - i] = c;
    sa -= k;
    --t;
  };
  while (sb < n) {
    if (sa == n) deal(b[sb]);
    if (a[sa] == b[sb]) {
      ++sa;
      ++sb;
    } else if (a[sa] > b[sb]) {
      if (t == 0) return 0;
      deal(b[sb]);
    } else {
      if (sa + k - 1 < n && a[sa] == a[sa + k - 1]) {
        ++t;
        sa += k;
      } else return 0;
    }
  }
  return 1;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Yes\n" : "No\n");
  }
  return 0;
}
