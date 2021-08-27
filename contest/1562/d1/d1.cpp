#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n, q;
  std::string s;
  std::cin >> n >> q >> s;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    a[i] = a[i - 1] + (s[i - 1] == '+' ^ (i & 1)  ? 1 : -1);
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    if (a[l - 1] == a[r]) std::cout << "0\n";
    else std::cout << ((r - l) % 2 ? 2 : 1) << '\n';
  }
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}