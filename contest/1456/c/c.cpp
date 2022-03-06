#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::sort(a.begin(), a.end());
  LL r = 0, cur = 0;
  int id = n - 1;
  while (id >= 0) {
    r += cur;
    if (cur + a[id] < 0) break;
    cur += a[id];
    --id;
  }
  cur = 0;
  while (id >= k) {
    r += cur;
    r += a[id];
    --id;
  }
  std::cout << r << std::endl;
  return 0;
}
