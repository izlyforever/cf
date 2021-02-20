#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, k;
		std::cin >> n >> k;
		std::string s;
		for (int i = 0; i < n; ++i) s += 'a' + (i % 3);
		std::cout << s << std::endl;
	}
	return 0;
}