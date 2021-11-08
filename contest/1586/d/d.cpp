#include <bits/stdc++.h>
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
  a[n] = 2;
  for (int i = 2; i <= n; ++i) {
    int x = query(a, n);
    if (x == 0) break;
    ans[x] = i - 1;
    ++a[n];
  }
  if (a[n] == 2) {
    ans[n] = n;
  } else {
    ans[n] = n + 2 - a[n];
    for (int i = 1; i < n; ++i) if (ans[i]) {
      ans[i] += ans[n];
    }
  }
  a = std::vector<int>(n + 1, n);
  for (int i = 2; i < ans[n]; ++i) {
    a[n] = n + i - ans[n];
    ans[query(a, n)] = i;
  }
  for (int i = 1; i < n; ++i) if (!ans[i]) {
    ans[i] = (ans[n] == 1 ? n : 1); // only once
    break;
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