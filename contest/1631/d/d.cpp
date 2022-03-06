#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> cnt(n + 1), a(n);
  for (auto &x : a) {
    std::cin >> x;
    ++cnt[x];
  }
  int diff = INT_MAX, x = 1, y = 1, sum = cnt[1];
  for (int i = 1, j = 2; i <= n; ++i) {
    while (j <= n && sum < n - sum + k) {
      sum += cnt[j];
      ++j;
    }
    if (sum < n - sum + k) break;
    if (diff > j - i) {
      diff = j - i;
      x = i;
      y = j - 1;
    }
    sum -= cnt[i];
  }
  std::cout << x << ' ' << y << '\n';
  int i = 0;
  while (--k) {
    int j = i, sum = 0;
    while (sum <= 0) {
      if (a[j] >= x && a[j] <= y) ++sum;
      else --sum;
      ++j;
    }
    std::cout << i + 1 << ' ' << j << '\n';
    i = j;
  }
  std::cout << i + 1 << ' ' << n << '\n';
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
