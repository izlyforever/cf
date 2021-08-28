#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    // 存一下开头的三个字符和结尾的三个字符，以及答案
    std::map<std::string, std::tuple<std::string, LL, std::string>> mp;
    for (int i = 0; i < n; ++i) {
      std::string x, op;
      std::cin >> x >> op;
      if (op[0] == '=') {
        std::string a, add, b;
        std::cin >> a >> add >> b;
        auto [aa, aans, ab] = mp[a];
        auto [ba, bans, bb] = mp[b];
        LL ans = aans + bans;
        switch (ab.size()) {
        case 3:
          if (ab == "hah" && ba[0] == 'a') ++ans;
        case 2:
          if (ab.substr(0, 2) == "ah" && ba.substr(0, 2) == "ha") ++ans;
        default:
          if (ab[0] == 'h' && ba == "aha") ++ans;
          break;
        }
        if (aa.size() < 3) {
          int now = 0;
          while (now < ba.size() && aa.size() < 3) aa += ba[now++];
        }
        if (bb.size() < 3) {
          int now = ab.size() - 1;
          while (now >= 0 && bb.size() < 3) bb += ab[now--];
        }
        mp[x] = {aa, ans, bb};
      } else {
        std::string c;
        std::cin >> c;
        int ans = 0;
        for (int j = 0, ns = c.size(); j + 3 < ns; ++j) {
          if (c.substr(j, 4) == "haha") ++ans;
        }
        std::string a = c.substr(0, 3), b;
        for (int i = 1; i <= 3 && i <= (int)c.size(); ++i) b += c[c.size() - i];
        mp[x] = {a, ans, b};
      }
      if (i == n - 1) {
        std::cout << std::get<1>(mp[x]) << '\n';
      }
    }
  }
  return 0;
}