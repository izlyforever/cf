#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

const int N = 5e6 + 2;
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> cnt(N);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++cnt[x];
  }
  std::vector<LL> ans(N);
  for (int i = 1; i < N; ++i) {
    ans[i] += 1LL * (i - 1) * cnt[i];
    for (int j = i + i; j < N; j += i) ans[j] = std::max(ans[j], ans[i]);
  }
  std::cout << *std::max_element(ans.begin(), ans.end()) + n << '\n';
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