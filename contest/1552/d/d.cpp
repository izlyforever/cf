#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// O(3^n)
bool solve1() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::function<bool(int, int, bool)> dfs = [&](int i, int s, bool flag) -> bool {
    if (s == 0 && flag) return true;
    if (i == n) return false;
    return dfs(i + 1, s, flag) | dfs(i + 1, s + a[i], true) | dfs(i + 1, s - a[i], true);
  };
  return dfs(0, 0, false);
}

bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  std::function<bool(int, int, bool)> dfs = [&](int i, int s, bool flag) -> bool {
    if (s == 0 && flag) return true;
    if (i == n) return false;
    return dfs(i + 1, s, flag) | dfs(i + 1, s + a[i], true) | dfs(i + 1, s - a[i], true);
  };
  return dfs(0, 0, false);
}

// O(n 3^{\frac{n}{2}})

bool solve2() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  if (std::count(a.begin(), a.end(), 0)) return true;

  std::map<int, int> mp1{{0, 0}};
  int n2 = n / 2;
  for (int i = 0; i < n2; ++i) {
    auto SS = mp1;
    for (auto [x, y] : SS) {
      mp1[x - a[i]] = mp1[x + a[i]] = y + 1;
    }
  }
  if (mp1[0] > 0) return true;

  std::map<int, int> mp2{{0, 0}};
  for (int i = n2; i < n; ++i) {
    auto SS = mp2;
    for (auto [x, y] : SS) {
      mp2[x - a[i]] = mp2[x + a[i]] = y + 1;
    }
  }
  if (mp2[0] > 0) return true;
  for (auto [x, y] : mp1) if (mp2.count(x) && (mp2[x] || y)) return true;
  return false;
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve2() ? "YES" : "NO") << '\n';
  }
  return 0;
}