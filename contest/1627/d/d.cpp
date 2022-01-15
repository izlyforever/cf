#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  const int N = 1e6 + 2;
  std::vector<int> cnt(N);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++cnt[x];
  }
  std::vector<int> val(N);
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      if (cnt[j]) ++val[i];
    }
  }
  int ans = 0;
  for (int i = N - 1; i >= 1; --i) if (val[i]) {
    bool flag = true;
    for (int j = i * 2; j < N; j += i) {
      if (val[j] == val[i]) {
        flag = false;
        break;
      }
    }
    if (flag) ++ans;
  }
  std::cout << ans - n << '\n';
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