#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

class MEX {
  inline static const int B = 20;
  std::array<std::map<int, int>, B> mp;
  std::set<int> S;
 public:
  void insert(int x) {
    if (S.count(x)) return;
    S.insert(x);
    int mask = 0;
    for (int i = B - 1; i >= 0; --i) {
      mask |= 1 << i;
      ++mp[i][x & mask];
    }
  }
  void erase(int x) {
    if (!S.count(x)) return;
    S.erase(x);
    int mask = 0;
    for (int i = B - 1; i >= 0; --i) {
      mask |= 1 << i;
      --mp[i][x & mask];
    }
  }
  // find mex(a_i ^ x)
  int solve(int x = 0) {
    int mask = 0, r = 0;
    for (int i = B - 1; i >= 0; --i) {
      mask |= x & (1 << i);
      if (mp[i][mask] == (1 << i)) {
        mask ^= 1 << i;
        r |= 1 << i;
      }
    }
    return r;
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  MEX A;
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    A.insert(x);
  }
  int now = 0;
  for (int i = 0, x; i < m; ++i) {
    std::cin >> x;
    now ^= x;
    std::cout << A.solve(now) << "\n";
  }
  return 0;
}
