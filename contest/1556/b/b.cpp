#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

int solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) {
    std::cin >> x;
    x &= 1;
  }
  int x = std::count(a.begin(), a.end(), 0);
  if (abs(n - 2 * x) > 1) return -1;
  LL ans = INT64_MAX;
  if (n - x <= x) {
    LL sm = 0;
    for (int i = 0, cur = 0; i < n; ++i) if (a[i] == 0) {
      sm += abs(i - cur);
      cur += 2;
    }
    ans = std::min(ans, sm);
  }
  if (n - x >= x) {
    LL sm = 0;
    for (int i = 0, cur = 1; i < n; ++i) if (a[i] == 0) {
      sm += abs(i - cur);
      cur += 2;
    }
    ans = std::min(ans, sm);
  }
  return ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}