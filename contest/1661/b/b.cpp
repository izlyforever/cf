#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

constexpr int N = 32768;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::vector<int> ans(N, -1);
  ans[0] = 0;
  std::queue<int> Q;
  Q.push(0);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    std::vector<int> a{(u + N - 1) % N};
    if (u % 2 == 0) {
      a.emplace_back(u >> 1);
      a.emplace_back((u >> 1) + N / 2);
    }
    for (auto v : a) {
      if (ans[v] == -1) {
        ans[v] = ans[u] + 1;
        Q.push(v);
      }
    }
  }
  int n;
  std::cin >> n;
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    std::cout << ans[x] << " \n"[i == n - 1];
  }
  return 0;
}
