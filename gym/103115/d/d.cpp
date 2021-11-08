#include <bits/stdc++.h>
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, l, r;
  std::string a;
  std::cin >> n >> l >> r >> a;
  if (l == r) {
    std::vector<std::string> s(r);
    for (int i = 0; i < n; ++i) {
      s[i % r].push_back(a[i]);
    }
    for (auto& x : s) std::sort(x.begin(), x.end());
    for (int i = 0; i < n; ++i) {
      a[i] = s[i % r][i / r];
    }
  } else if (l < (n + 1) / 2) {
    std::sort(a.begin(), a.end());
  } else {
    std::string s;
    for (int i = 0; i < n - l; ++i) s.push_back(a[i]);
    for (int i = l; i < n; ++i) s.push_back(a[i]);
    std::sort(s.begin(), s.end());
    for (int i = 0; i < n - l; ++i) a[i] = s[i];
    for (int i = n - 1; i >= l; --i) {
      a[i] = s.back();
      s.pop_back();
    }
  }
  std::cout << a << '\n';
  return 0;
}