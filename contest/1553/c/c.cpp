#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  std::string s;
  std::cin >> s;
  int ans = 10;
  {
    std::vector<int> A(10);
    for (int i = 0; i < 10; i += 2) A[i] = (s[i] != '0');
    for (int i = 1; i < 10; i += 2) A[i] = (s[i] == '1');
    int now = 0;
    for (int i = 0; i < 10; ++i) {
      if (A[i]) now += (i & 1 ? -1 : 1);
      if (now > (10 - i) / 2) {
        ans = std::min(ans, i + 1);
        break;
      }
    }
  }
  {
    std::vector<int> A(10);
    for (int i = 0; i < 10; i += 2) A[i] = (s[i] == '1');
    for (int i = 1; i < 10; i += 2) A[i] = (s[i] != '0');
    int now = 0;
    for (int i = 0; i < 10; ++i) {
      if (A[i]) now += (i & 1 ? 1 : -1);
      if (now > (9 - i) / 2) {
        ans = std::min(ans, i + 1);
        break;
      }
    }
  }
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
