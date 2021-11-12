#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int query(int l, int r) {
  std::cout << l << ' ' << r << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  int l = 1, r = n;
  while (r > l) {
    int m = (l + r) / 2;
    if (query(l, m)) r = m;
    else l = m + 1;
  }
  std::cout << "! " << r << std::endl;
  return 0;
}