#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<LL> a(n);
  for (auto& x : a) std::cin >> x;
  if (n == 1) {
    std::cout << "1 1" << std::endl;
    std::cout << -a[0] << std::endl;
    std::cout << "1 1" << std::endl;
    std::cout << 0 << std::endl;
    std::cout << "1 1" << std::endl;
    std::cout << 0 << std::endl;
    return 0;
  }
  std::cout << "1 " << n << std::endl;
  std::cout << "0 ";
  for (int i = 1; i < n; ++i) {
    LL tmp = -a[i] * n % (n - 1) * n;
    std::cout << tmp << " \n"[i == n - 1];
    a[i] += tmp;
  }
  std::cout << "1 1\n";
  std::cout << -a[0] << std::endl;
  std::cout << "2 " << n << std::endl;
  for (int i = 1; i < n; ++i) {
    std::cout << -a[i] << " \n"[i == n - 1];
  }
  return 0;
}