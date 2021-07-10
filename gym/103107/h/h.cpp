#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, T;
	std::cin >> n >> T;
	for (int i = n - 1; i > 0; --i) {
		std::cout << n << ' ' << i << '\n';
	}
	std::cout << n << ' ' << n << '\n';
	return 0;
}