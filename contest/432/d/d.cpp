#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

std::vector<int> prefixFunction(std::string s) {
  int n = s.size();
  std::vector<int> p(n);
  for (int i = 1; i < n; ++i) {
    int j = p[i - 1];
    while (j > 0 && s[i] != s[j]) j = p[j - 1];
    if (s[i] == s[j]) ++j;
    p[i] = j;
  }
  return p;
}

// 返回 长度为 i 的前缀出现的次数
std::vector<int> countPrefix(std::string s) {
  auto p = prefixFunction(s);
  int n = s.size();
  std::vector<int> ans(n + 1);
  for (auto x : p) ++ans[x];
  for (int i = n - 1; i > 0; --i) ans[p[i - 1]] += ans[i];
  for (int i = 0; i <= n; ++i) ++ans[i];
  return ans;
}
// 返回 s 长度为 i 的前缀在 t 中出现的次数
std::vector<int> countPrefix(std::string s, std::string t) {
  auto p = prefixFunction(s);
  int n = s.size(), m = t.size();
  std::vector<int> ans(n + 1);
  for (int i = 0, j = 0; i < m; ++i) {
    while (j > 0 && t[i] != s[j]) j = p[j - 1];
    if (t[i] == s[j]) ++j;
    ++ans[j];
  }
  ++ans[0];
  for (int i = n; i > 0; --i) ans[p[i - 1]] += ans[i];
  return ans;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  auto p = prefixFunction(s);
  auto ans = countPrefix(s);
  std::stack<int> r;
  int now = s.size();
  while (now > 0) {
    r.push(now);
    now = p[now - 1];
  }
  std::cout << r.size() << "\n";
  while (!r.empty()) {
    std::cout << r.top() << " " << ans[r.top()] << "\n";
    r.pop();
  }
  return 0;
}