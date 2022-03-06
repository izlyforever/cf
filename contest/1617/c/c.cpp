#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int solve() {
  int n;
  std::cin >> n;
  std::multiset<int> S;
  std::vector<int> cnt(n + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (x <= n && cnt[x] == 0) {
      ++cnt[x];
    } else {
      S.insert(x);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) if (cnt[i] == 0) {
    int u = *S.begin();
    S.erase(S.begin());
    if (u <= 2 * i) return -1;
    ++ans;
  }
  return ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}
