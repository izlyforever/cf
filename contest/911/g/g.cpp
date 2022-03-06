#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::vector<char> ca(n);
  for (int i = 0; i < n; ++i) ca[i] = a[i];
  int q;
  std::cin >> q;
  while (q--) {
    int l, r, x, y;
    std::cin >> l >> r >> x >> y;
    char cx = x, cy = y;
    for (int i = l - 1; i < r; ++i) {
      ca[i] = (ca[i] == cx ? cy : ca[i]);
    }
  }
  for (int i = 0; i < n; ++i) a[i] = ca[i];
  for (auto x : a) std::cout << x << ' ';
  std::cout << '\n';
  return 0;
}
