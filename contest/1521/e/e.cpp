#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  auto f = [](int n) {
    return (n + 1) / 2 * n;
  };
  auto g = [](int n) {
    return n * n - (n / 2) * (n / 2);
  };
  while (cas--) {
    int m, k;
    std::cin >> m >> k;
    std::vector<std::pair<int, int>> a(k);
    for (int i = 0, x; i < k; ++i) {
      std::cin >> x;
      a[i] = {x, i + 1};
    }
    std::sort(a.begin(), a.end(), std::greater<>());
    int l = 0, r = 1e4, mx = a[0].first;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (f(mid) >= mx && g(mid) >= m) r = mid - 1;
      else l = mid + 1;
    }
    int n = l;
    std::vector<std::vector<int>> b(n, std::vector<int>(n));
    int now = 0;
    // 这三个循环顺序不能变！
    for (int i = 1; i < n; i += 2) {
      for (int j = 0; j < n; j += 2) {
        while (now < a.size() && a[now].first == 0) ++now;
        if (now == a.size()) break;
        b[i][j] = a[now].second;
        --a[now].first;
      }
      if (now == a.size()) break;
    }
    for (int i = 0; i < n; i += 2) {
      for (int j = 0; j < n; j += 2) {
        while (now < a.size() && a[now].first == 0) ++now;
        if (now == a.size()) break;
        b[i][j] = a[now].second;
        --a[now].first;
      }
      if (now == a.size()) break;
    }
    for (int i = 0; i < n; i += 2) {
      for (int j = 1; j < n; j += 2) {
        while (now < a.size() && a[now].first == 0) ++now;
        if (now == a.size()) break;
        b[i][j] = a[now].second;
        --a[now].first;
      }
      if (now == a.size()) break;
    }
    std::cout << n << '\n';
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cout << b[i][j] << " \n"[j == n - 1];
      }
    }
  }
  return 0;
}