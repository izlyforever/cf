#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;


// 根据情况换成 bool
bool solve() {
	std::string s;
	std::cin >> s;
	int l = 0, r = s.size() - 1, x = r;
	while (l <= r) {
		if (s[l] - 'a' == x) {
			++l;
		} else if (s[r] - 'a' == x) {
			--r;
		} else return false;
		--x;
	}
	return true;
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