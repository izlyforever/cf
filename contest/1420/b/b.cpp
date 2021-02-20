#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl;
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		LL cnt[31] = {};
		for (int i = 0; i < n; ++i) {
			int id = 0, x;
			std::cin >> x;
			while(x) {
				++id;
				x >>= 1;
			}
			++cnt[id];
		}
		LL r = 0;
		for (int i = 1; i < 31; ++i) r += cnt[i] * (cnt[i] - 1) / 2;
		print(r);
	}
	return 0;
}