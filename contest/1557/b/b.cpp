#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;


// Returns the original value corresponding to the array value after discretization
template <typename T>
std::vector<T> discrete(std::vector<T>& a) {
  auto b = a;
  std::sort(b.begin(), b.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());
  for (auto& x : a) {
    x = std::lower_bound(b.begin(), b.end(), x) - b.begin();
  }
  return b;
}

bool solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  discrete(a);
  int x = 1;
  for (int i = 1; i < n; ++i) if (a[i] - a[i - 1] != 1) {
    ++x;
  }
  return x <= k;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Yes" : "No") << '\n';
  }
  return 0;
}
