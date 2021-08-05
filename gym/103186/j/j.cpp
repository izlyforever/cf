#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  LL s = std::accumulate(a.begin(), a.end(), 0LL);
  if (s < 0) for (auto &x : a) x = -x;
  std::sort(a.begin(), a.end(), std::greater<>());
  LL s1 = 0, s2 = 0;
  for (int i = 0; i < n; i += 2) s1 += a[i];
  for (int i = 1; i < n; i += 2) s2 += a[i];
  std::cout << abs(s1) - abs(s2) << '\n';
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