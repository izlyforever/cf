#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

const int A = 1e5; // max bound of value in a
const int N = 1e5; // max bound of size of a
const int SN = std::sqrt(N) + 1; // SN * SN > N
const int C = A + SN * N;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), cnt(2 * C + 1);
  for (auto &x : a) std::cin >> x;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int step = 1; step < SN && step + i < n; ++step) {
      if ((a[i + step] - a[i]) % step == 0) {
        ans = std::max(ans, ++cnt[C + (a[i + step] - a[i]) / step]);
      }
    }
    for (int step = 1; step < SN && step + i < n; ++step) {
      if ((a[i + step] - a[i]) % step == 0) {
        --cnt[C + (a[i + step] - a[i]) / step];
      }
    }
  }
  ++ans;
  for (int d = -SN; d <= SN; ++d) {
    for (int i = 0; i < n; ++i) {
      ans = std::max(ans, ++cnt[C + a[i] + d * i]);
    }
    for (int i = 0; i < n; ++i) {
      --cnt[C + a[i] + d * i];
    }
  }
  std::cout << n - ans << '\n';
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
