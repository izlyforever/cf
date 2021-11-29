#undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

const int N = 2e7 + 2;
bool isp_[N]{};
std::vector<int> p_{0, 2};
// $O(N \log \log N)$ but faster when N < 1e9
void initPrime() {
  p_.reserve(N / 10);
  isp_[2] = true;
  for (int i = 3; i < N; i += 2) isp_[i] = true;
  int sq = int(std::sqrt(N + 0.1)) | 1; // make sure it is odd number
  for (int i = 3; i <= sq; i += 2) if (isp_[i]) {
    p_.emplace_back(i);
    for (int j = i * i; j < N; j += i << 1) isp_[j] = false;
  }
  for (int i = sq + 2; i < N; i += 2) if (isp_[i]) p_.emplace_back(i);
}
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> cnt(N);
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    ++cnt[x];
  }
  auto tot = cnt;
  for (int i = 1; i < N; ++i) {
    for (int j = i + i; j < N; j += i) {
      tot[i] += cnt[j];
    }
  }
  std::vector<LL> dp(N);
  for (int i = N - 1, pn = p_.size(); i > 0; --i) {
    dp[i] = 1LL * i * tot[i];
    for (int j = 1; j < pn; ++j) {
      int p = p_[j];
      if (p * i >= N) break;
      dp[i] = std::max(dp[i], dp[i * p] + 1LL * (tot[i] - tot[i * p]) * i);
    }
  }
  std::cout << dp[1] << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  initPrime();
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}