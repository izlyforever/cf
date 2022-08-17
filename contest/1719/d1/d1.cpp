#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int f(std::vector<int>& a) {
  int sum = 0;
  std::set<int> S{0};
  int ans = 0;
  for (auto &x : a) {
    if (S.count(x ^ sum)) {
      S.clear();
      S.insert(0);
      sum = 0;
    } else {
      ++ans;
      sum ^= x;
      S.insert(sum);
    }
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::cout << f(a) << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
