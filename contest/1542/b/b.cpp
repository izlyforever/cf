#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
bool solve() {
	int n, a, b;
	std::cin >> n >> a >> b;
	if ((n - 1) % b == 0) return true;
	if (a == 1) return false;
	for (LL x = a; x <= n; x *= a) if ((n - x) % b == 0) return true;
	return false;
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas; // 根据情况注释掉
	while (cas--) {
		std::cout << (solve() ? "Yes" : "No") << '\n';
	}
	return 0;
}