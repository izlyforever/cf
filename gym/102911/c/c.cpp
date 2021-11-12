#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int N = 5e6 + 2;
int sp[N], p[N], sg[N];
int spf() {
  int cnt = 1;
  p[1] = 2;
  for (int i = 2; i < N; i += 2) sp[i] = 2;
  for (int i = 1; i < N; i += 2) sp[i] = i;
  for (int i = 3; i < N; i += 2) {
    if (sp[i] == i) p[++cnt] = i;
    for (int j = 1; j <= cnt && p[j] <= sp[i] && i * p[j] < N; ++j) { //防止乘法溢出
      sp[i * p[j]] = p[j]; // 注意到sp只被赋值一次
    }
  }
  sg[1] = 1;
  for (int i = 2; i < N; ++i) sg[i] = sg[i / sp[i]] + 1;
  return cnt;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  spf();
  int m, n, x, y;
  std::cin >> m >> n >> x >> y;
  std::map<int, int> mp;
  for (int i = 0; i <= x; ++i) {
    ++mp[sg[m - i]];
  }
  LL r = 0;
  for (int i = 0; i <= y; ++i) {
    r += x + 1 - mp[sg[n - i]];
  }
  std::cout << r << std::endl;
  return 0;
}