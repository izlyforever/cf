#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  freopen("collectingofficer.in","r",stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> a(n, INT_MIN);
    for (int i = 0; i < n; ++i) if (s[i] == 'A') a[i] = i;
    for (int i = 0; i < n; ++i) if (s[i] != 'A') {
      for (int j = 0 ; j < i; ++j) {
        if (s[i] == s[j] + 1) {
          a[i] = std::max(a[i], a[j]);
        }
      }
    }
    int r = INT_MAX;
    for (int i = 0; i < n; ++i) if (s[i] == 'Z' && a[i] != INT_MIN) {
      r = std::min(r, i - a[i] + 1);
    }
    std::cout << r << std::endl;
  }
  return 0;
}
