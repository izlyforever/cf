#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 1; i < n; ++i) {
    std::cout << "XOR 1 " << i + 1 << std::endl;
    std::cin >> a[i];
  }
  int x = -1;
  std::vector<int> b(n, -1);
  for (int i = 0; i < n; ++i) {
    if (b[a[i]] == -1) b[a[i]] = i;
    else {
      std::cout << "AND " << b[a[i]] + 1 << " " << i + 1 << std::endl;
      int tmp;
      std::cin >> tmp;
      x = tmp ^ a[i];
      break;
    }
  }
  if (x == -1) {
    int t1, t2;
    std::cout << "AND " << b[1] + 1 << " " << b[n - 1] + 1 << std::endl;
    std::cin >> t1;
    t1 = t1 * 2 + n - 2;
    std::cout << "AND " << 1 << " " << b[1] + 1 << std::endl;
    std::cin >> t2;
    t2 = t2 * 2 + 1;
    x = (n - 1 + t1 + t2) / 2 - t1;
  }
  std::cout << "! " << x;
  for (int i = 1; i < n; ++i) std::cout << " " << (x ^ a[i]);
  std::cout << std::endl;
  return 0;
}
