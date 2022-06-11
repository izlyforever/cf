#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::string a, b;
  std::cin >> a >> b;
  std::sort(a.begin(), a.end(), std::greater<>());
  std::sort(b.begin(), b.end(), std::greater<>());
  std::string c;
  int now = 0;
  while (!a.empty() && !b.empty()) {
    if (now == k) {
      now = -1;
      c += b.back();
      b.pop_back();
    } else if (now == -k) {
      now = 1;
      c += a.back();
      a.pop_back();
    } else {
      if (a.back() == b.back()) {
        int cnt = 0;
        char cur = a.back();
        while (!a.empty() && a.back() == cur) {
          a.pop_back();
          ++cnt;
        }
        while (!b.empty() && b.back() == cur) {
          b.pop_back();
          ++cnt;
        }
        now = 0;
        c += std::string(cnt, cur);
      } else if (a.back() < b.back()) {
        now = std::max(now, 0) + 1;
        c += a.back();
        a.pop_back();
      } else {
        now = std::min(now, 0) - 1;
        c += b.back();
        b.pop_back();
      }
    }
  }
  std::cout << c << '\n';
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
