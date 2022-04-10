#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  std::vector<int> a{4, 3, 2, 1};
  // Transitivity is not satisfied, so the result is not as expected
  std::stable_sort(a.begin(), a.end(), [&](auto i, auto j){
      if ((i ^ j) & 1) return false;
      return i < j;
  });
  for (auto x : a) std::cout << x << ' ';
  std::cout << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
