#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), ans(n);
  for (auto &x : a) std::cin >> x;
  if (n & 1) {
    if (a[0] + a[1] != 0) {
      ans[0] = ans[1] = -a[2];
      ans[2] = a[0] + a[1];
    } else if (a[0] + a[2] != 0) {
      ans[0] = ans[2] = -a[1];
      ans[1] = a[0] + a[2];
    } else {
      ans[1] = ans[2] = -a[0];
      ans[0] = a[1] + a[2];
    }
    for (int i = 3; i < n; i += 2) {
      ans[i] = a[i + 1];
      ans[i + 1] = -a[i];
    }
  } else {
    for (int i = 0; i < n; i += 2) {
      ans[i] = a[i + 1];
      ans[i + 1] = -a[i];
    }
  }
  for (auto &x : ans) std::cout << x << ' ';
  std::cout << '\n';
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
