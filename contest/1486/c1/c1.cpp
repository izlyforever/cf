#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

std::map<std::pair<int, int>, int> mp;
int cnt = 0;
int query(int l, int r) {
  if (l == r) return --cnt;
  if (mp.count({l, r})) return mp[{l, r}];
  std::cout << "? " << l << " " << r << std::endl;
  int ans;
  std::cin >> ans;
  return mp[{l, r}] = ans;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  int l = 1, r = n;
  while (r - l > 1) {
    int m = (l + r) / 2;
    int q = query(l, r);
    if (m <= q) {
      int qq = query(m, r);
      if (qq == q) {
        l = m;
        mp[{l, r}] = q;
      } else {
        r = m - 1;
      }
    } else {
      int qq = query(l, m);
      if (qq == q) {
        r = m;
        mp[{l, r}] = q;
      } else {
        l = m + 1;
      }
    }
  }
  if (r - l == 1) r = l + r - query(l, r);
  std::cout << "! " << r << std::endl;
  return 0;
}