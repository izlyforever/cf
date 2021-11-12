#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int N = 1e7 + 2;
bool isp[N];
std::vector<int> p{0, 2};
// 此算法复杂度为 O(N \log \log N)，实测 N < 1e9 时是最快的
void initPrime() {
  isp[2] = true;
  for (int i = 3; i < N; i += 2) isp[i] = true;
  int sq = int(std::sqrt(N + 0.1)) | 1;
  for (int i = 3; i <= sq; i += 2) if (isp[i]) {
    p.emplace_back(i);
    for (int j = i * i; j < N; j += i << 1) isp[j] = false;
  }
  for (int i = sq + 2; i < N; i += 2) if (isp[i]) p.emplace_back(i);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  initPrime();
  auto f = [](int n, int i) {
    int r = 0;
    while (n) {
      n /= p[i];
      r += n;
    }
    return r;
  };
  auto solve = [&]() -> bool {
    int l1, r1, l2, r2;
    std::cin >> l1 >> r1 >> l2 >> r2;
    int sz = std::upper_bound(p.begin(), p.end(), std::max(r1, r2)) - p.begin();
    for (int i = 1; i < sz; ++i) {
      if (f(r1, i) - f(l1 - 1, i) > f(r2, i) - f(l2 - 1, i)) return false;
    }
    return true;
  };
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Yes\n" : "No\n");
  }
  return 0;
}