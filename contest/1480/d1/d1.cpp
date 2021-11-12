#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  auto check = [&](int l, int r, int val) {
    for (int i = l + 2; i < r; i += 2) {
      if (a[i] != val) return false;
    }
    return true;
  };
  int r = 1, now = 1, last = -1, la = -1;
  for (int i = 1; i < n; ++i) {
    ++r;
    if (a[i] == a[i - 1]) {
      if (last == a[i] && check(la, i, a[i])) --r;
      while (i < n && a[i] == a[i - 1]) ++i;
      la = --i;
      last = a[i];
    }
  }
  std::cout << r << "\n";
  return 0;
}