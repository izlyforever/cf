#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(m);
  for (auto& x : a) std::cin >> x;
  for (auto& x : b) std::cin >> x;
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  std::multiset<int> S(b.begin(), b.end());
  int ans = 0;
  for (auto x : a) {
    while (!S.empty() && *S.begin() <= x) {
      ++ans;
      x -= *S.begin();
      S.erase(S.begin());
    }
  }
  std::cout << ans << '\n';
  return 0;
}