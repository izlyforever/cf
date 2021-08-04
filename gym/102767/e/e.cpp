#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int N = 1e7 + 2; // 再大内存吃不消了
int sp[N], p[N];
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
  return cnt;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  spf();
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, a, b, c;
    std::cin >> n >> a >> b >> c;
    int r = n + c;
    if (int sn = sp[n]; sn != n) {
      if (sp[n / sn] != n / sn) r = std::min(r, b + sn);
      int x = n;
      while (sp[n] != n) n /= sp[n];
      r = std::min(r, a + x / n);
    }
    std::cout << r << std::endl;
  }
  return 0;
}