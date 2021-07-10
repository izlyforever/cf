#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
int f(int n) {
	if (n == 1) return 0;
	if (n == 2) return 1;
	if (n == 3) return 2;
	if (n % 2 == 0) return 2;
	return 3;
}
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::cout << f(n) << std::endl;
	}
	return 0;
}