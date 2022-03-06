#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  int n;
  std::vector<int> a(4), b(6);
  std::cin >> n;
  for (auto& x : a) std::cin >> x;
  for (int i = 0; i < 4; ++i) if (a[i] == n) {
    ++b[(i + 3) % 4];
    ++b[(i + 1) % 4];
    b[4 + i % 2] += 2;
  }
  for (int i = 0; i < 4; ++i) if (a[i] == n - 1) {
    ++b[4 + i % 2];
  }
  for (int i = 0; i < 4; ++i) if (a[i] < b[i]) return 0;
  if (a[0] + a[2] < b[5]) return 0;
  if (a[1] + a[3] < b[4]) return 0;
  return 1;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES\n" : "NO\n");
  }
  return 0;
}
