#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int f(int x) {
  int r = 0;
  while (x) {
    r += x % 10;
    x /= 10;
  }
  return r;
}

void solve() {
  int s, n;
  std::cin >> s >> n;
  std::vector<int> a;
  int x = s, ten = 1;
  while (x) {
    a.emplace_back(x % 10);
    x /= 10;
    if (x) ten *= 10;
  }
  int i = a.size() - 1;
  while (n > 1) {
    while (a[i] == 0) {
      --i;
      ten /= 10;
    }
    --a[i];
    if (s - ten >= n - 1) {
      std::cout << ten << ' ';
      s -= ten;
      --n;
    } else {
      a[i - 1] += 10;
    }
  }
  std::cout << s << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
