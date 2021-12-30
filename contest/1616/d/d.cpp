#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// -1, 1, -1, .....
//
// -1, 1, -1,

// -2 3 -2

// -1 1, -1, -3, 2

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int mean;
  std::cin >> mean;
  for (auto &x : a) x -= mean;

  int ans = n, sm = 0, now = 0, count = 0;
  while (now < n) {
    ++count;
    sm += a[now];
    if (sm < 0) {
      if (count > 1) {
        --ans;
        sm = 0;
        count = 0;
      }
    } else {
      sm = std::min(sm, a[now]);
    }
    ++now;
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