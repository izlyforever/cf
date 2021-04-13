#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, k;
		std::cin >> n >> k;
		int nk = n * k;
		std::vector<int> a(nk);
		for (auto &x : a) std::cin >> x;
		int l = n / 2 + 1;
		LL r = 0;
		for (int i = 0; i < k; ++i) {
			nk -= l;
			r += a[nk];
		}
		std::cout << r << std::endl;
	}
	return 0;
}