#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    bool flag = true;
    int now = a[0], cur = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] < cur) {
        flag = false;
        break;
      }
      if (a[i] > a[i - 1]) {
        cur += a[i] - a[i - 1];
      } else {
        now -= a[i] - a[i - 1];
        if (now < 0) {
          flag = false;
          break;
        }
      }
    }
    std::cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}