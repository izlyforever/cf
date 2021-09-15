#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::vector<int> b(n), c(n);
  auto f = [&](int i) {
    return i > 0 && i + 1 < n && (a[i] > std::max(a[i - 1], a[i + 1]) || a[i] < std::min(a[i - 1], a[i + 1]));
  };
  int ans = 0;
  for (int i = 1; i + 1 < n; ++i) ans += f(i);
  auto check = [&](int i) {
    return f(i - 1) + f(i) + f(i + 1);
  };
  int r = ans;
  for (int i = 1; i + 1 < n; ++i) {
    int t = a[i];
    ans -= check(i);

    a[i] = a[i - 1];
    ans += check(i);
    r = std::min(r, ans);
    ans -= check(i);

    a[i] = a[i + 1];
    ans += check(i);
    r = std::min(r, ans);
    ans -= check(i);

    a[i] = t;
    ans += check(i);
  }
  return r;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << std::endl;
  }
  return 0;
}