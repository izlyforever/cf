#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

// clear 和 26 两个 bug
const int N = 102;
int a[N][N];

// n % 2 == 0
bool f(int n, int m, int k) {
  if (k & 1 || ((m & 1) && k * 2 > n * (m - 1))) return false;
  int i = 1, j = 1, now = 0, k2 = n * m / 2 - k;
  while (k--) {
    while (a[i - 1][j] == now || a[i][j - 1] == now) if (++now == 26) now = 0;
    a[i][j] = a[i][j + 1] = now++;
    if (now == 26) now = 0;
    if (++i > n) {
      i = 1;
      j += 2;
    }
  }
  while (k2--) {
    while (a[i][j] != -1) if (++i > n) {
      i = 1;
      j += 1;
    }
    while (a[i - 1][j] == now || a[i][j - 1] == now || a[i + 1][j - 1] == now) if (++now == 26) now = 0;
    a[i][j] = a[i + 1][j] = now++;
    if (now == 26) now = 0;
  }
  return true;
}
void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  if (n % 2 == 0) {
    bool flag = f(n, m, k);
    if (!flag) {
      std::cout << "NO\n";
      return;
    }
    std::cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        std::cout << char(a[i][j] + 'a');
      }
      std::cout << '\n';
    }
  } else {
    bool flag = f(m, n, m * n / 2 - k);
    if (!flag) {
      std::cout << "NO\n";
      return;
    }
    std::cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        std::cout << char(a[j][i] + 'a');
      }
      std::cout << '\n';
    }
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    memset(a, -1, sizeof(a));
    solve();
  }
  return 0;
}
