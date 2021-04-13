#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		print(std::max({a, b, c}));
	}
	return 0;
}