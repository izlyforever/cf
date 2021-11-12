#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int query(int i, int j) {
  int r;
  std::cout << "? " << i << ' ' << j << std::endl;
  std::cin >> r;
  return r;
}

// a x^2 + b x + c = 0
LL solve(LL a, LL b, LL c) {
  LL x = (std::sqrt(b * b - 4 * a * c) - b) / (2 * a);
  if (a * x * x + b * x + c == 0) return x;
  return (-std::sqrt(b * b - 4 * a * c) - b) / (2 * a);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, s;
  std::cin >> n >> s;
  int x = query(2, 1) - s + 1;
  if (n == 2) {
    int x2 = solve(1, x, -s);
    int x1 = x2 + x;
    std::cout << "! " << x1 << ' ' << x2 << std::endl;
    return 0;
  }
  std::vector<int> a(n);
  for (int i = 1; i + 2 <= n; ++i) {
    a[i - 1] = query(i + 2, i) - s;
  }
  std::vector<std::pair<LL, LL>> c(n + 1);
  int now = n - 3;
  LL rnow = -a[now];
  while (now > 4) {
    now -= 4;
    rnow = rnow - a[now];
  }
  c[2] = {1, 0};
  c[now] = {0, rnow};
  c[4 - now] = {1, x - rnow};
  for (int i = 4; i <= n; ++i) {
    c[i] = {c[i - 4].first, c[i - 4].second + a[i - 4]};
  }
  LL c0 = 0, c1 = 0, c2 = 0;
  for (int i = 1; i < n; ++i) {
    c0 += c[i].first * c[i + 1].first;
    c1 += c[i].first * c[i + 1].second + c[i].second * c[i + 1].first;
    c2 += c[i].second * c[i + 1].second;
  }
  LL r2 = solve(c0, c1, c2 - s);
  std::vector<LL> r(n + 1);
  for (int i = 1; i <= n; ++i) {
    r[i] = c[i].first * r2 + c[i].second;
  }
  std::cout << "! ";
  for (int i = 1; i <= n; ++i) {
    std::cout << r[i];
    if (i != n) std::cout << ' ';
  }
  std::cout << std::endl;
  return 0;
}