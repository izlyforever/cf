#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  auto check = [](std::vector<int> a) {
    int now = 0;
    for (auto x : a) {
      now = x - now;
      if (now < 0) return false;
    }
    return now == 0;
  };
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    std::vector<int> b(n + 1, -1);
    b[0] = 0;
    for (int i = 0; i < n && b[i] >= 0; ++i) {
      b[i + 1] = a[i] - b[i];
    }
    if (b[n] == 0) {
      std::cout << "YES\n";
      continue;
    }
    bool flag = false;
    int now = 0;
    for (int i = n - 1; i > 0 && now >= 0; --i) {
      if (b[i - 1] >= 0 && check(std::vector<int>({b[i - 1], a[i], a[i - 1], now}))) {
        flag = true;
        break;
      }
      now = a[i] - now;
    }
    std::cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}