#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::string a, b;
  std::cin >> n >> a >> b;
  int ans = 0;
  int cur = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) std::swap(a[i], b[i]);
    if (a[i] == '0' && b[i] == '1') {
      ans += 2;
      if (cur == 0) ++ans;
      cur = -1;
      continue;
    }
    if (cur == 0) {
      if (b[i] == '1') {
        ans += 2;
        cur = -1;
      } else {
        ++ans;
      }
    } else if (cur == 1) {
      if (a[i] == '0') {
        ans += 2;
        cur = -1;
      }
    } else {
      if (a[i] == '0') {
        cur = 0;
        if (b[i] == '1') {
          cur = -1;
          ans += 2;
        }
      } else {
        cur = 1;
      }
    }
  }
  if (cur == 0) ++ans;
  std::cout << ans << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}