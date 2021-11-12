#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::string s;
  std::cin >> n >> s;
  LL ans = 0, cur = 0;
  std::vector<int> left(n + 1, -1);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') ans += cur;
    else {
      int l = i, r = i;
      while (r < n && s[r] == '1') ++r;
      int len = 0;
      for (i = l; i < r; ++i) {
        ++len;
        cur += i - left[len];
        ans += cur;
        left[len] = r - len;
      }
      --i;
    }
  }
  print(ans);
  return 0;
}