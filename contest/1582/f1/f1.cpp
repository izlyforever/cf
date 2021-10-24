#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;
const int N = 512;

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> cnt(N, N);
  cnt[0] = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    auto now = cnt;
    for (int i = 0; i < N; ++i) if (cnt[i] < x) {
      now[i ^ x] = std::min(now[i ^ x], x);
    }
    std::swap(cnt, now);
  }
  int x = N - std::count(cnt.begin(), cnt.end(), N);
  std::cout << x << '\n';
  for (int i = 0; i < N; ++i) if (cnt[i] != N) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
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