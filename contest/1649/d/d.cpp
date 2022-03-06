#undef _GLIBCXX_DEBUG
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int read() {
  int x = 0;
  char ch = getchar();
    while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

void solve() {
  int n = read(), c = read();
  int c2 = c * 2;
  std::vector<int> cnt(c2 + 1);
  for (int i = 0; i < n; ++i) {
    int x = read();
    ++cnt[x];
  }
  auto sm = cnt;
  for (int i = 1; i <= c2; ++i) sm[i] += sm[i - 1];
  for (int i = 1; i <= c; ++i) if (cnt[i]) {
    for (int j = 1, ij = i; ij <= c; ++j, ij += i) {
      if (cnt[j] == 0 && sm[ij + i - 1] != sm[ij - 1]) {
        printf("No\n");
        return;
      }
    }
  }
  printf("Yes\n");
}

int main() {
  // std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = read();
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}