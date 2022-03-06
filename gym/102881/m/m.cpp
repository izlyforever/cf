#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  freopen("lis.in","r",stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  std::reverse(s.begin(), s.end());
  while (s.back() == '0') s.pop_back();
  int now = 0;
  while (now < s.size() && s[now] == '9') ++now;
  int r = 9 * (s.size() - 1) + (s.back() - '0');
  if (now + 1 < s.size()) --r;
  std::cout << r << std::endl;
  return 0;
}
