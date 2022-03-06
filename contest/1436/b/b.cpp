#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

const int N = 1e3 + 2;
bool isp[N];
std::vector<int> p;

void initPrimeP() {
  p.emplace_back(2);
  isp[2] = true;
  for (int i = 3; i < N; i += 2) isp[i] = true;
  for (int i = 3; i < N; i += 2) {
    if (isp[i]) p.emplace_back(i);
    for (int j = 1, t = (N - 1) / i + 1; j != p.size() && p[j] < t; ++j) { // 用除号是防止溢出
      isp[i * p[j]] = false;
      // 不要下面的一步的话，复杂度 O(nloglogn), 但是不用除法，常数小
      if (i % p[j] == 0) break;
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  initPrimeP();
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n - 1);
    int u = *std::lower_bound(p.begin(), p.end(), 4 * n) - 1 - 4 * (n - 2);
    a[0] = u;
    for (int i = 1; i < n - 1; ++i) a[i] = 4;
    std::vector<int> r(n);
    for (int i = 0; i < n; ++i) {
      r[i] = 1;
      for (int j = i + 1; j % n != i; ++j) r[j % n] = a[j - 1 - i];
      for (int j = 0; j < n; ++j) std::cout << r[j] << " \n"[j == n - 1];
    }
  }
  return 0;
}
