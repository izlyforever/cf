#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> a;
    a.emplace_back(1);
    char now = s[0];
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == now) ++a.back();
      else {
        a.emplace_back(1);
        now = s[i];
      }
    }
    int cnt = 0, ans = 0;
    for (auto x : a) {
      if (cnt >= n) break;
      ++ans;
      ++cnt;
      cnt = std::max(0, cnt - (x - 1));
      n -= x;
    }
    print(ans);
  }
  return 0;
}