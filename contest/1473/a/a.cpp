#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, d;
    std::cin >> n >> d;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    auto ai = std::min_element(a.begin(), a.end());
    int r = INT_MAX;
    for (auto it = a.begin(); it != a.end(); ++it) if (it != ai) {
      r = std::min(r, *it);
    }
    std::cout << (r + *ai <= d || *std::max_element(a.begin(), a.end()) <= d ? "YES\n" : "NO\n");
  }
  return 0;
}