#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  int mx[2]{INT_MAX, INT_MAX};
  int pos[2]{};
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (mx[i & 1] > x) {
      mx[i & 1] = x;
      pos[i & 1] = i;
    }
  }
  if (n & 1) {
    return true;
  }
  if (mx[0] != mx[1]) {
    return mx[0] > mx[1];
  }
  return pos[0] > pos[1];
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Mike" : "Joe") << '\n';
  }
  return 0;
}
