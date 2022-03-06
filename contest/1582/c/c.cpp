#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  auto f = [&](char x) {
    int l = 0, r = n - 1, ans = 0;
    while (l < r) {
      if (s[l] != s[r]) {
        ++ans;
        if (s[l] == x) {
          ++l;
        } else if (s[r] == x) {
          --r;
        } else {
          return n;
        }
      } else {
        ++l;
        --r;
      }
    }
    return ans;
  };
  int ans = n;
  for (char x = 'a'; x <= 'z'; ++x) {
    ans = std::min(ans, f(x));
  }
  std::cout << (ans == n ? -1 : ans) << '\n';
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
