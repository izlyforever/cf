#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  bool vis[k][k]{}, v[k]{}, flag = true;
  std::vector<int> a{0};
  while (flag) {
    flag = false;
    for (int i = 0; i < k; ++i) if (!v[i] && !vis[a.back()][i]) {
      vis[a.back()][i] = true;
      v[a.back()] = true;
      for (int j = 0; j < k; ++j) if (!vis[a.back()][j]) v[a.back()] = false;
      a.emplace_back(i);
      flag = true;
      break;
    }
  }
  std::string s;
  for (auto x : a) s += char(x + 'a');
  for (int i = 0; i < n; ++i) std::cout << s[i % s.size()];
  std::cout << '\n';
  return 0;
}