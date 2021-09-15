#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::vector<std::pair<int, int>> r, n1, n2, n3;
  int now = n;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == 1) {
      n1.push_back({now, i + 1});
      r.push_back({now, i + 1});
      --now;
    } else if (a[i] == 2) {
      if (n1.size() == 0) {
        print(-1);
        return 0;
      }
      n2.push_back({n1.back().first, i + 1});
      r.push_back({n2.back().first, i + 1});
      n1.pop_back();
    } else if (a[i] == 3) {
      if (n3.size() + n2.size() + n1.size() == 0) {
        print(-1);
        return 0;
      }
      if (n3.size()) {
        r.push_back({now, n3.back().second});
        n3.pop_back();
      } else if (n2.size()) {
        r.push_back({now, n2.back().second});
        n2.pop_back();
      } else {
        r.push_back({now, n1.back().first});
        n1.pop_back();
      }
      n3.push_back({now, i + 1});
      r.push_back({now, i + 1});
      --now;
    }
  }
  print(r.size());
  for (auto [x, y] : r) std::cout << x << " " << y << std::endl;
  return 0;
}