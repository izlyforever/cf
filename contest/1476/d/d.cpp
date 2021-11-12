#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;


std::pair<std::vector<int>, std::vector<int>> f(std::string s) {
  int n = s.size();
  std::vector<int> a(n + 1, 0), b(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') a[i + 1] = a[i] + 1;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'R') b[i] = b[i + 1] + 1;
  }
  return {a, b};
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::string ss[2];
    ss[0] = ss[1] = s;
    for (int i = 1; i < n; i += 2) ss[0][i] = (ss[0][i] == 'L' ? 'R' : 'L');
    for (int i = 0; i < n; i += 2) ss[1][i] = (ss[1][i] == 'L' ? 'R' : 'L');
    std::vector<int> a[2], b[2];
    std::tie(a[0], b[0]) = f(ss[0]);
    std::tie(a[1], b[1]) = f(ss[1]);
    std::vector<int> c(n + 1, 1);
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'L') {
        c[i + 1] += a[i & 1][i + 1];
      } else {
        c[i] += b[i & 1][i];
      }
    }
    for (int i = 0; i <= n; ++i) std::cout << c[i] << " \n"[i == n];
  }
  return 0;
}