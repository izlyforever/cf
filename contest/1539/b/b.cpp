#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n, q;
  std::string s;
  std::cin >> n >> q >> s;
  std::vector<int> a{0};
  for (auto& x : s) a.emplace_back(a.back() + (x - 'a' + 1));
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << a[r] - a[l - 1] << '\n';
  }
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}