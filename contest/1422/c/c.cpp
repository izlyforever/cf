#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
const LL M = 1e9 + 7;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::string a;
	std::cin >> a;
	LL r = 0, n = 0, id = 1, r2 = 0;
	for (auto x : a) {
		r = (r * 10 + id * (id - 1) / 2 * (x - '0') + r2) % M;
		n = (n * 10 + (x - '0')) % M;
		r2 += n;
		++id;
	}
	print(r);
	return 0;
}