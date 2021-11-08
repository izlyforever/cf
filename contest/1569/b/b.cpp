#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  std::vector<std::string> a(n, std::string(n, '='));
  for (int i = 0; i < n; ++i) a[i][i] = 'X';
  std::vector<int> b;
  for (int i = 0; i < n; ++i) if (s[i] == '2') {
    b.emplace_back(i);
  }
  if (!b.empty() && b.size() < 3) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
    if (!b.empty()) {
      for (int i = 1, m = b.size(); i < m; ++i) {
        a[b[i]][b[i - 1]] = '-';
        a[b[i - 1]][b[i]] = '+';
      }
      a[b.front()][b.back()] = '-';
      a[b.back()][b.front()] = '+';
    }
    for (auto &x : a) std::cout << x << '\n';
  }
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}