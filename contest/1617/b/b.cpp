#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

const int N = 1e6 + 2;
bool isp_[N];
std::vector<int> p_{0, 2};
// $O(N \log \log N)$ but faster when N < 1e9
void initPrime() {
  p_.reserve(N);
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
  --n;
  for (int i = 1; p_[i] < n; ++i) {
    if (n % p_[i]) {
      std::cout << p_[i] << ' ' << n - p_[i] << " 1\n";
      return;
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  initPrime();
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}