#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
using pii = std::pair<int, int>;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<pii> a(m);
  for (auto &[l, r] : a) std::cin >> l >> r;
  std::sort(a.begin(), a.end(), [](const pii &A, const pii &B) {
    return A.first + A.second < B.first + B.second;
  });
  std::vector<int> sm(m + 1);
  for (int i = 0; i + k <= n; ++i) {
    int cur = 0;
    for (int j = m - 1; j >= 0; --j) {
      cur += std::max(0, std::min(i + k, a[j].second) - std::max(i, a[j].first - 1));
      sm[j] = std::max(sm[j], cur);
    }
  }
  int ans = sm[0];
  for (int i = 0; i + k <= n; ++i) {
    int cur = 0;
    for (int j = 0; j < m; ++j) {
      cur += std::max(0, std::min(i + k, a[j].second) - std::max(i, a[j].first - 1));
      ans = std::max(ans, cur + sm[j + 1]);
    }
  }
  std::cout << ans << std::endl;
  return 0;
}