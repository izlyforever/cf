#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int N = 2e5 + 5;
bool isp[N];
std::vector<int> p;
int initPrimeP() {
  p.emplace_back(2);
  isp[2] = true;
  for (int i = 3; i < N; i += 2) isp[i] = true;
  int sq = int(std::sqrt(N + 0.1))|1;
  for (int i = 3; i <= sq; i += 2) if (isp[i]) {
    p.emplace_back(i);
    for (int j = i * i; j < N; j += i << 1) {
      isp[j] = false;
    }
  }
  for (int i = sq + 2; i < N; i += 2) if (isp[i]) p.emplace_back(i);
  return p.size();
}

std::pair<LL, int> solve(LL n) {
  LL r = 0;
  int cnt = 0;
  for (auto x : p) {
    if (LL(x) * x > n) break;
    if (n % x == 0) {
      int t = 0;
      while (n % x == 0) {
        n /= x;
        ++t;
      }
      if (t > cnt) {
        cnt = t;
        r = x;
      }
    }
  }
  if (n > 1 && cnt == 0) {
    cnt = 1;
    r = n;
  }
  return {r, cnt};
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  initPrimeP();
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    LL n;
    std::cin >> n;
    auto [r, cnt] = solve(n);
    std::cout << cnt << std::endl;
    for (int i = 1; i < cnt; ++i) {
      std::cout << r << " ";
      n /= r;
    }
    std::cout << n << std::endl;
  }
  return 0;
}