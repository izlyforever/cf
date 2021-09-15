#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  int n;
  LL A, B;
  std::cin >> A >> B >> n;
  std::vector<LL> a(n), b(n);
  for (auto& x : a) std::cin >> x;
  for (auto& x : b) std::cin >> x;
  std::vector<int> r;
  LL mx = 0, sm = 0;
  for (int i = 0; i < n; ++i) {
    sm += (b[i] + A - 1) / A * a[i];
  }
  B -= sm - *std::max_element(a.begin(), a.end());
  return B > 0;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES\n" : "NO\n");
  }
  return 0;
}