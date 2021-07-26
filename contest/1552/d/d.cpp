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
  bool ok = false;
  std::function<void(int, int, bool)> dfs = [&](int i, int s, bool flag) {
    if (s == 0 && flag) ok = true;
    if (ok || i == n) return;
    if (!ok) dfs(i + 1, s, flag);
    if (!ok) dfs(i + 1, s + a[i], true);
    if (!ok) dfs(i + 1, s - a[i], true);
  };
  dfs(0, 0, false);
  return ok;
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