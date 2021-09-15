#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    std::set<int> s;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) s.insert(a[j] - a[i]);
    }
    std::cout << s.size() << std::endl;
  }
  return 0;
}