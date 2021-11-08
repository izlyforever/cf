#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

int f(std::vector<int> a) {
  a.insert(a.end(), a.begin(), a.end());
  int n = a.size(), i = 0;
  int ans = 0;
  while (i < n) {
    while (i < n && a[i] == 0) ++i;
    int now = i;
    while (i < n && a[i] == 1) ++i;
    ans = std::max(ans, i - now);
  }
  return ans == n ? INT_MAX : ans;
}
void solve() {
  int n, d;
  std::cin >> n >> d;
  std::vector<int> a(n), b(n);
  for (auto &x : a) std::cin >> x;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i]) { continue; }
    int j = i;
    std::vector<int> tmp;
    do {
      b[j] = 1;
      tmp.emplace_back(a[j]);
      j += d;
      if (j >= n) j -= n;
    } while (j != i);
    ans = std::max(ans, f(std::move(tmp)));
  }
  std::cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}