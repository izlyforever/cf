#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  std::function<bool(int, int, bool)> dfs = [&](int i, int s, bool flag) -> bool {
    if (s == 0 && flag) return true;
    if (i == n) return false;
    return dfs(i + 1, s, flag) | dfs(i + 1, s + a[i], true) | dfs(i + 1, s - a[i], true);
  };
  return dfs(0, 0, false);
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas; // 根据情况注释掉
	while (cas--) {
		std::cout << (solve() ? "YES" : "NO") << '\n';
	}
	return 0;
}