#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// 首先注意到，根据奇偶性 n % 4 为 0, 1 才有可能
// 打表找规律，发现好多可行解，我一开始以为可以把 n 变 n - 4 来处理，未果。
// 原来是 n 分成 4 块处理才行，以下是解读 Nezzar 的做法

// n = 4 k 的情况
// 0     , ..., k - 1,  k, k + 1, ..., 2k - 1, 2k, 2k + 1, ..., 3k - 1, 3k,    3k + 1, ..., 4k - 1
// 4k - 1, ..., 3k,     k, 3k - 1,..., 2k + 1,  0,     2k, ...,  k + 2, k + 1,   k - 1,..., 1
// 4k - 1, ..., 2k + 1, 0, 2k - 2,..., 2,      2k,      1, ..., 2k - 3, 2k - 1, 2k + 2,..., 4k - 2

// n = 4 k + 1 的情况
// 0     , ..., k - 1,  k, k + 1, ..., 2k - 1, 2k,     2k + 1, 2k + 2,..., 3k + 1, 3k + 2, ..., 4k
// 4k    , ..., 3k + 1, k, 3k   , ..., 2k + 2, 2k + 1, 0,          2k,...,  k + 1,  k - 1,...,  1
// 4k    , ..., 2k + 2, 0, 2k - 1,..., 3,      1,      2k + 1,      2,...,     2k, 2k + 3,..., 4k - 1

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  if (n % 4 > 1) {
    std::cout << "NO\n";
    return 0;
  }
  int k = n / 4, now = n;
  std::vector<int> a;
  for (int i = 0; i < k; ++i) a.emplace_back(--now);
  if (k) a.emplace_back(k);
  for (int i = 1; i < k; ++i) a.emplace_back(--now);
  if (n & 1) a.emplace_back(--now);
  if (k) a.emplace_back(0);
  for (int i = 0; i < k; ++i) a.emplace_back(--now);
  --now;
  for (int i = 1; i < k; ++i) a.emplace_back(--now);
  std::cout << "YES\n";
  for (auto x : a) std::cout << x << ' ';
  std::cout << '\n';
  return 0;
}