#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  auto it = std::max_element(a.begin(), a.end()) - a.begin();
  bool flag = true;
  for (int i = 0; i < n; ++i) if (a[it] % a[i]) {
    flag = false;
    break;
  }
  std::cout << (flag ? it + 1 : -1) << std::endl;
  return 0;
}