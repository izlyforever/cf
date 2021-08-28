#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

bool check(int x) {
  return x % 10 != 3 && x % 3 != 0;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::vector<int> a;
  int now = 1;
  while (a.size() < 1000) {
    while (!check(now)) ++now;
    a.emplace_back(now++);
  }
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    int x;
    std::cin >> x;
    std::cout << a[x - 1] << '\n';
  }
  return 0;
}