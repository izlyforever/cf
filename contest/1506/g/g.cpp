#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::string s;
    std::cin >> s;
    std::vector<int> lst(26, -1);
    int now = -1;
    for (auto c : s) lst[c - 'a'] = ++now;
    std::vector<int> a, cnt(26);
    for (int i = 0; i < s.size(); ++i) if (!cnt[s[i] - 'a']) {
      while (!a.empty() && s[a.back()] < s[i] && lst[s[a.back()] - 'a'] > i) {
        --cnt[s[a.back()] - 'a'];
        a.pop_back();
      }
      cnt[s[i] - 'a'] = 1;
      a.emplace_back(i);
    }
    for (auto x : a) std::cout << s[x];
    std::cout << '\n';
  }
  return 0;
}