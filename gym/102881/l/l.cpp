#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
const LL M = 1e9 + 7;
LL powMod(LL x, LL n) {
	LL r = 1;
	while (n) {
		if (n & 1) r = r * x % M;
		n >>= 1;   x = x * x % M;
	}
	return r;
}
 
int main() {
	freopen("exor.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		LL n;
		std::cin >> n;
		LL n2 = powMod(2, n);
		std::cout << n2 * (2 * n2 - 1) % M << std::endl;
	}
	return 0;
}