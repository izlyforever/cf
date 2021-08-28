#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  for (int i = 0; i + 2 < n; ++i) {
    if ((a[i] ^ a[i + 1]) > a[i + 2]) return 1;
    if (a[i] > (a[i + 1] ^ a[i + 2])) return 1;
  }
  int ans = INT_MAX;
  for (int i = 1; i < n; ++i) {
    std::vector<int> b, c;
    int nb = 0;
    for (int j = i - 1; j >= 0; --j) {
      nb ^= a[j];
      b.emplace_back(nb);
    }
    int nc = 0;
    for (int j = i; j < n; ++j) {
      nc ^= a[j];
      c.emplace_back(nc);
    }
    for (int j = 0; j < b.size(); ++j) {
      for (int k = 0; k < c.size(); ++k) if (b[j] > c[k]) {
        ans = std::min(ans, j + k);
      }
    }
  }
  return ans == INT_MAX ? -1 : ans;
}
int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << solve() << std::endl;
  return 0;
}