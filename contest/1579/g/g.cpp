#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void cmin(int &x, int y) {
  if (x > y) x = y;
}
// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  const int N = 2000;
  std::vector<int> b(N); // b[i] 表示 离左端点为 i 但是离右端点为 b[i]
  for (auto x : a) {
    std::vector<int> c(N, INT_MAX);
    for (int i = 0; i < N; ++i) {
      cmin(c[std::max(0, i - x)], b[i] + x);
    }
    for (int i = 0; i + x < N; ++i) {
      cmin(c[i + x], std::max(b[i] - x, 0)); 
    }
    std::swap(b, c);
  }
  int ans = INT_MAX;
  for (int i = 0; i < N; ++i) {
    ans = std::min(ans, i + b[i]);
  }
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