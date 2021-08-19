#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

std::string check(const std::string &a, char c) {
  std::string b;
  for (auto &x : a) if (x != c) b += x;
  return b;
}
// 根据情况换成 bool
bool solve(std::string& ans, std::string& order) {
  std::string t;
  std::cin >> t;
  int cnt[26]{};
  for (int i = t.size() - 1; i >= 0; --i) if (cnt[t[i] - 'a']++ == 0) {
    order += t[i];
  }
  int n = order.size();
  for (int i = 1; i <= n; ++i) {
    if (cnt[order[n - i] - 'a'] % i) return false;
    cnt[order[n - i] - 'a'] /= i;
  }
  for (int i = n, sz = 0; i >= 1; --i) {
    sz += cnt[order[n - i] - 'a'];
    auto now = t.substr(t.size() - sz);
    if (check(now, order[n - i]) != ans) return false;
    ans = std::move(now);
    t.resize(t.size() - sz);
  }
  std::reverse(order.begin(), order.end());
  return true;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    std::string ans, order;
    if (solve(ans, order)) {
      std::cout << ans << ' ' << order << '\n';
    } else {
      std::cout << "-1\n";
    }
  }
  return 0;
}