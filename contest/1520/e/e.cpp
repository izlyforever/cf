#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::deque<int> a;
    for (int i = 0; i < n; ++i) if (s[i] == '*') a.emplace_back(i);
    LL r = 0;
    while (a.size() > 1) {
      r += a.back() - a.front() - a.size() + 1;
      a.pop_back();
      a.pop_front();
    }
    std::cout << r << '\n';
  }
  return 0;
}