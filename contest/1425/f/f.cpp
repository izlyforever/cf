#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl;
using LL = long long;

int main() {;
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::cout << "? 1 " << n << std::endl;
  int s, tmp;
  std::cin >> s;
  for (int i = 0; i + 2 < n; ++i) {
    std::cout << "? " << i + 2 << " " << n << std::endl;
    std::cin >> tmp;
    a[i] = s - tmp;
    s = tmp;
  }
  std::cout << "? " << n - 2 << " " << n - 1 << std::endl;
  std::cin >> tmp;
  a[n - 2] = tmp - a[n - 3];
  a[n - 1] = s - a[n - 2];
  std::cout << "! ";
  for (auto x : a) std::cout << x << " ";
  println;
  return 0;
}