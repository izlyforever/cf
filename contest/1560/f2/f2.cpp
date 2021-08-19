#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

std::string dfs(const std::string &s, int k) {
  int n = s.size();
  std::set<char> S;
  int i = 0;
  while (i < n) {
    if (!S.count(s[i])) {
      if (S.size() == k) {
        auto it = S.lower_bound(s[i]);
        if (it == S.end()) {
          std::string cur = s.substr(0, i - 1) + char(s[i - 1] + 1) + std::string(n - i, '0');
          return dfs(cur, k);
        } else {
          return s.substr(0, i) + (*it) + std::string(n - i - 1, *S.begin());
        }
      } else {
        S.insert(s[i]);
      }
    }
    ++i;
  }
  return s;
}

// 根据情况换成 bool
void solve() {
  int n, k;
  std::cin >> n >> k;
  std::cout << dfs(std::to_string(n), k) << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}