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
  int l = 1, r = n, q = query(l, r);
  while (l < r) {
    int m = (l + r) / 2;
    if (q <= m) {
      if (l == m && q == l) {
        l = m + 1;
        continue;
      }
      int qq = query(std::min(q, l), m);
      if (qq == q) r = m;
      else l = m + 1;
    } else {
      if (m + 1 == r && q == r) {
        r = m;
        continue;
      }
      int qq = query(m + 1, std::max(r, q));
      if (qq == q) l = m + 1;
      else r = m;
    }
  }
  std::cout << "! " << r << std::endl;
  return 0;
}