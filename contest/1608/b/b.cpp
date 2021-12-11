#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

std::vector<int> f(int n, int a, int b) {
  std::vector<int> ans;
  ans.reserve(n);
  if (a == b) {
    for (int i = 0; i <= b; ++i) {
      ans.emplace_back(i + 1);
      ans.emplace_back(b + 1 + i + 1);
    }
    for (int i = 2 * b + 3; i <= n; ++i) {
      ans.emplace_back(i);
    }
  } else {
    for (int i = 0; i <= b; ++i) {
      ans.emplace_back(i + 1);
      ans.emplace_back(n - i);
    }
    for (int i = n - b - 1; i > b + 1; --i) {
      ans.emplace_back(i);
    }
  }
  return ans;
}

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  std::vector<int> ans;
  if (abs(a - b) > 1 || a + b > n - 2) {
    std::cout << "-1\n";
  } else {
    if (a >= b) {
      ans = f(n, a, b);
    } else {
      ans = f(n, b, a);
      for (auto &x : ans) x = n + 1 - x;
    }
  }
  for (auto x : ans) std::cout << x << ' ';
  std::cout << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}