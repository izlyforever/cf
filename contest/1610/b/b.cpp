#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  auto check = [&](int l, int r, int x) -> bool {
    while (l <= r) {
      if (a[l] == a[r]) {
        ++l;
        --r;
      } else {
        if (a[l] == x) {
          ++l;
        } else if (a[r] == x) {
          --r;
        } else {
          return false;
        }
      }
    }
    return true;
  };
  int l = 0, r = n - 1;
  while (l <= r && a[l] == a[r]) {
    ++l;
    --r;
  }
  if (l > r) return true;
  return check(l, r, a[l]) || check(l, r, a[r]);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}