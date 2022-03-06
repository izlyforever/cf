#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n, k;
  LL x;
  std::string s;
  std::cin >> n >> k >> x >> s;
  --x;
  std::vector<int> star;
  int now = 0;
  while (now < n) {
    while (now < n && s[now] == 'a') ++now;
    if (now < n) {
      star.emplace_back(1);
      while (now < n && s[now] == '*') {
        ++now;
        star.back() += k;
      }
    }
  }
  LL cur = 1;
  int id = star.size() - 1;
  while (id >= 0) {
    if (star[id] > x / cur) break;
    cur *= star[id];
    --id;
  }
  for (int i = 0; i < id; ++i) star[i] = 0;
  for (int i = std::max(0, id), sz = star.size(); i < sz; ++i) {
    star[i] = x / cur;
    x %= cur;
    if (i + 1 < sz) cur /= star[i + 1];
  }
  now = 0;
  id = 0;
  while (now < n) {
    while (now < n && s[now] == 'a') {
      ++now;
      std::cout << 'a';
    }
    if (now < n) {
      while (now < n && s[now] == '*') ++now;
      std::cout << std::string(star[id++], 'b');
    }
  }
  std::cout << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
