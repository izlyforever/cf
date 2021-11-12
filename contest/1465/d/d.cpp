#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string a;
  LL x, y;
  std::cin >> a >> x >> y;
  if (x > y) {
    std::swap(x, y);
    std::reverse(a.begin(), a.end());
  }
  int n = a.size();
  std::vector<int> p[2], s[2];
  p[0].resize(n + 1);
  p[1].resize(n + 1);
  s[0].resize(n + 1);
  s[1].resize(n + 1);
  for (int i = 0; i < n; ++i) {
    p[0][i + 1] = p[0][i];
    p[1][i + 1] = p[1][i];
    if (a[i] != '?') ++p[a[i] - '0'][i + 1];
  }
  for (int i = n - 1; i >= 0; --i) {
    s[0][i] = s[0][i + 1];
    s[1][i] = s[1][i + 1];
    if (a[i] != '?') ++s[a[i] - '0'][i];
  }
  LL ord = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == '0') ord += p[1][i] * y;
    if (a[i] == '1') ord += p[0][i] * x;
  }
  std::vector<LL> pre(n + 1), suf(n + 1);
  for (int i = 0; i < n; ++i) {
    pre[i + 1] = pre[i];
    if (a[i] == '?') pre[i + 1] += s[1][i] * x + p[1][i] * y;
  }
  for (int i = n - 1; i >= 0; --i) {
    suf[i] = suf[i + 1];
    if (a[i] == '?') suf[i] += s[0][i] * y + p[0][i] * x;
  }
  int cnt = std::count(a.begin(), a.end(), '?'), tnc = 0;
  LL r = ord + suf[0];
  for (int i = 0; i < n; ++i) if (a[i] == '?') {
    ++tnc;
    r = std::min(r, ord + pre[i + 1] + suf[i + 1] + x * (cnt - tnc) * tnc);
  }
  std::cout << r << std::endl;
  return 0;
}