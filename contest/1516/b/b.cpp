#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  int r = 0;
  for (auto& x : a) r ^= x;
  if (r == 0) return 1;
  int now = 0, cnt = 0;;
  for (auto& x : a) {
    now ^= x;
    if (now == r) {
      now = 0;
      ++cnt;
    }
  }
  return now == 0 && cnt > 1;
}
int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {

    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}