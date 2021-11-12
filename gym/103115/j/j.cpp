#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  const int N = 1e6 + 2;
  std::vector<int> cnt(N);
  int n;
  std::cin >> n;
  for (int i = 0, x; i < n; ++ i) {
    std::cin >> x;
    ++cnt[x];
  }
  int ans = 0;
  for (int i = 1; i < N; i += 2) {
    int c[2]{}; // c[0] 表示当前位置被处理了，c[1] 表示没处理
    for (int j = i; j < N; j *= 2) {
      c[1] = std::min(c[0], c[1]) + cnt[j];
      std::swap(c[0], c[1]);
    }
    ans += std::min(c[0], c[1]);
  }
  std::cout << ans << '\n';
  return 0;
}