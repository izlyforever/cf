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

bool kmp(std::string s, std::string t) {
  std::vector<int> ans;
  int n = s.size(), m = t.size();
  if (n > m) return 0;
  auto p = prefixFunction(s);
  for (int i = 0, j = 0; i < m; ++i) {
    while (j > 0 && s[j] != t[i]) j = p[j - 1];
    if (s[j] == t[i] && ++j == n) return 1;
  }
  return 0;
}


int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  auto p = prefixFunction(s);
  auto t = s.substr(1, s.size() - 2);
  int now = p.back();
  while (now > 0) {
    if (kmp(s.substr(0, now), t)) break;
    now = p[now - 1];
  }
  if (now > 0) std::cout << s.substr(0, now) << "\n";
  else std::cout << "Just a legend\n";
  return 0;
}