#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;


const int N = 1e6 + 2;
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
  int n, e;
  std::cin >> n >> e;
  std::vector<int> a(n);
  for (auto &x : a) {
    std::cin >> x;
    if (x != 1) {
      x = isp_[x] ? 0 : -1;
    }
  }
  LL ans = 0;
  for (int i = 0; i < e; ++i) {
    int j = i, n1 = 0, n2 = 0;
    while (j < n) {
      if (a[j] == -1) n1 = 0;
      while (j < n && a[j] == -1) j += e;
      while (j < n && a[j] == 1) {
        j += e;
        ++n1;
      }
      if (j < n && a[j] == 0) {
        j += e;
        while (j < n && a[j] == 1) {
          j += e;
          ++n2;
        }
        ans += LL(n1 + 1) * (n2 + 1) - 1;
        n1 = n2;
        n2 = 0;
      }
    }
  }
  std::cout << ans << '\n';
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
