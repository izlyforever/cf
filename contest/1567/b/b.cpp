#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

const int N = 3e5 + 2;
int dp[N];
void init() {
  for (int i = 1; i < N; ++i) dp[i] = dp[i - 1] ^ i;
}

void solve() {
  int a, b;
  std::cin >> a >> b;
  int ans = a;
  b ^= dp[a - 1];
  if (b > 0) ++ans;
  if (b == a) ++ans;
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}