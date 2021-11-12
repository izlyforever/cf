#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

LL c;
LL solve() {
  int n;
  std::cin >> n;
  std::vector<LL> a(n);
  for (auto& x : a) std::cin >> x;
  std::set<LL> S;
  for (int i = 1; i < n; ++i) {
    S.insert(a[i] - a[i - 1]);
  }
  if (S.size() <= 1) return 0;
  if (S.size() > 2) return -1;
  if (*S.begin() >= 0 || *S.rbegin() <= 0) return -1;
  c = *S.rbegin();
  LL m = c - *S.begin(), now = a[0] % m;
  for (int i = 0; i < n; ++i) {
    if (now != a[i]) return -1;
    now += c;
    if (now >= m) now -= m;
  }
  return m;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int m = solve();
    if (m <= 0) std::cout << m << '\n';
    else std::cout << m << ' ' << c << '\n';
  }
  return 0;
}