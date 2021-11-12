#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

const int M = 998244353;
const int N = 502;
int c[N][N], p[N][N], ans[N][N];
void init() {
  for (int i = 0; i < N; ++i) c[i][0] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < N; ++j) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
      if (c[i][j] >= M) c[i][j] -= M;
    }
  }
  for (int j = 0; j < N; ++j) p[0][j] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      p[i][j] = 1LL * p[i - 1][j] * j % M;
    }
  }
  for (int i = 1; i < N; ++i) ans[0][i] = 1;
  for (int i = 2; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i > j) {
        ans[i][j] = p[i][j];
      } else {
        for (int k = 0; k <= i; ++k) {
          ans[i][j] = (ans[i][j] + 1LL * ans[i - k][j - i + 1] * c[i][k] % M * p[k][i - 1]) % M;
        }
      }
    }
  }
}

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::cout << ans[n][x] << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}