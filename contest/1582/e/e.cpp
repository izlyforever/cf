#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<LL> a(n);
  for (auto &x : a) std::cin >> x;
  std::reverse(a.begin(), a.end());
  for (int i = 1; i < n; ++i) a[i] += a[i - 1];
  auto gets = [&](int l, int r) {
    return a[r] - (l == 0 ? 0 : a[l - 1]);
  };
  std::vector<std::vector<LL>> mx(n);
  int B = std::sqrt(2 * n) + 2;
  for (int i = 0; i < n; ++i) {
    mx[i].assign(B, 0);
    if (i) mx[i] = mx[i - 1];
    mx[i][1] = std::max(mx[i][1], gets(i, i));
    for (int j = 2; j < B; ++j) {
      if (i >= j) {
        LL cur = gets(i - j + 1, i);
        if (cur < mx[i - j][j - 1]) mx[i][j] = std::max(mx[i][j], cur);
      }
      if (i >= B) {
        mx[i - B].clear();
        mx[i - B].shrink_to_fit();
      }
    }
  }
  int ans = -1;
  for (int i = 0; i < B; ++i) {
    if (mx.back()[i] > 0) ans = i;
  }
  std::cout << ans << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}