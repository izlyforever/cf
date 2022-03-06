#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;

  std::vector<bool> isp(n + 1);
  std::vector<int> small, large;
  int sq = int(std::sqrt(n)) | 1;
  isp[2] = true;
  if (sq > 2) small.emplace_back(2);
  for (int i = 3; i <= n; i += 2) isp[i] = true;
  for (int i = 3; i <= sq; i += 2) {
    if (isp[i]) small.emplace_back(i);
    for (int j = i * i; j <= n; j += i * 2) {
      isp[j] = false;
    }
  }

  int tmp;
  for (auto x : small) {
    std::cout << "B " << x << std::endl;
    std::cin >> tmp;
  }

  int r = 1;
  for (auto x : small) {
    while (r * x <= n) {
      std::cout << "A " << r * x << std::endl;
      std::cin >> tmp;
      if (tmp == 1) r *= x;
      else break;
    }
  }

  int cnt;
  std::cout << "A 1" << std::endl;
  std::cin >> cnt;

  for (int i = sq + 1; i * r <= n; ++i) if (isp[i]) large.emplace_back(i);
  int sz = large.size();
  while (sz) {
    int m = sz / 2;
    for (int i = m; i < sz; ++i) {
      std::cout << "B " << large[i] << std::endl;
      std::cin >> tmp;
      if (tmp > 1) {
        std::cout << "C " << r * large[i] << std::endl;
        return 0;
      }
    }
    std::cout << "A 1" << std::endl;
    std::cin >> tmp;
    if (cnt - tmp != sz - m) {
      for (int i = m; i < sz; ++i) {
        std::cout << "A " << large[i] << std::endl;
        std::cin >> tmp;
        if (tmp) {
          std::cout << "C " << large[i] << std::endl;
          return 0;
        }
      }
    }
    cnt = tmp;
    sz = m;
  }
  std::cout << "C " << r << std::endl;
  return 0;
}
