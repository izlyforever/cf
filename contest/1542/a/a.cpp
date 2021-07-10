#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
bool solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(2 * n);
	for (auto &x : a) std::cin >> x, x &= 1;
	return n == std::count(a.begin(), a.end(), 1);
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