#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int h, w;
  std::cin >> h >> w;
  std::vector<std::string> s(h);
  for (auto& x : s) std::cin >> x;
  int r = 0, a = 0, b = 0;
  while (a < h && b < w) {
    if (s[a][b] == '*') ++r;
    int tmp = 0, ia = a, jb = b;
    for (int i = a; i < h; ++i) {
      for (int j = b; j < w; ++j) if (s[i][j] == '*') {
        if (tmp == 0) {
          tmp = i - a + j - b;
          ia = i;
          jb = j;
        } else if (tmp > i - a + j - b) {
          tmp = i - a + j - b;
          ia = i;
          jb = j;
        }
      }
    }
    if (ia == a && jb == b) break;
    a = ia;
    b = jb;
  }
  std::cout << r << '\n';
  return 0;
}
