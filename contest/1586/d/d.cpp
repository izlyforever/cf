#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

int query(const std::vector<int> &a, int n) {
  std::cout << "?";
  for (int i = 1; i <= n; ++i) std::cout << ' ' << a[i];
  std::cout << std::endl;
  int x;
  std::cin >> x;
  return x;
}

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1, 1), ans(n + 1);
  a[n] = n;
  // 看最后一个数是多少
  for (int i = 0; i < n; ++i) {
    if (query(a, n)) {
      ans.back() = i + 1;
      break;
    }
    --a.back();
  }
  if (ans.back() == 0) ans.back() = n;
  for (int i = ans[n] + 1; i <= n; ++i) {
    a[n] = i - ans[n] + 1;
    ans[query(a, n)] = i;
  }
  a = std::vector<int>(n + 1, n);
  for (int i = 1; i < ans[n]; ++i) {
    a[n] = n + i - ans[n];
    ans[query(a, n)] = i;
  }
  std::cout << "!";
  for (int i = 1; i <= n; ++i) std::cout << ' ' << ans[i];
  std::cout << std::endl;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}