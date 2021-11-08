#include <bits/stdc++.h>
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::string now("a");
    while (s.find(now) != std::string::npos) {
      int sz = now.size();
      while (sz > 0 && now[sz - 1] == 'z') --sz;
      if (sz == 0) now = std::string((int)now.size() + 1, 'a');
      else {
        ++now[sz - 1];
        for (int i = sz; i < now.size(); ++i) now[i] = 'a';
      }
    }
    std::cout << now << '\n';
  }
  return 0;
}