#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  if (std::all_of(a.begin(), a.end(), [&](const int& t) { return t == x;})) return 0;
  if (std::any_of(a.begin(), a.end(), [&](const int& t) { return t == x;})) return 1;
  int s = std::accumulate(a.begin(), a.end(), 0);
  if (x * n == s) return 1;
  return 2;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}