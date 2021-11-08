#include <bits/stdc++.h>
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, p1, p2, l;
  std::string s;
  std::cin >> n >> s >> p1 >> p2 >> l;
  --p1; --p2;
  auto a = s, b = s;
  for (int i = 0; i < l; ++i) a[i + p2] = a[i + p1];
  for (int i = 0; i < l; ++i) b[i + p2] = s[i + p1];
  std::cout << a << '\n';
  std::cout << b << '\n';
  return 0;
}