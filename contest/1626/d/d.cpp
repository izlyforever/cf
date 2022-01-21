#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int N = 2e5 + 2;
std::vector<int> val(N);
void init() {
  int now = 1;
  for (int i = 1; i < N; ++i) {
    val[i] = now;
    if ((i & -i) == i) {
      now *= 2;
    }
  }
  val[0] = 1;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> cnt(n + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++cnt[x];
  }
  int ans = val[n] + 2, id = 1, l = 0;
  while (id <= n) {
    while (id <= n && val[l] == val[l + cnt[id]]) {
      l += cnt[id];
      ++id;
    }
    if (id > n) break;
    int m = 0;
    for (int i = id; i <= n; ++i) {
      m += cnt[i];
      ans = std::min(ans, val[l] + val[m] + val[n - l - m]);
    }
    l += cnt[id];
    ++id;
  }
  std::cout << ans - n << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}