#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
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
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; ++i) std::cin >> a[i];
		std::vector<int> now(n + 1);
		std::vector<int> d(n + 1, -1);
		for (int i = 1; i <= n; ++i) {
			int x = a[i];
			d[x] = std::max(d[x], i - now[x]);
			now[x] = i;
		}
		for (int i = 1; i <= n; ++i) if (d[i] != -1) {
			d[i] = std::max(d[i], n + 1 - now[i]);
		}
		//for (int i = 1; i <= n; ++i) watch(d[i]);
		std::vector<int> r(n + 1, -1);
		int t = n;
		for (int i = 1; i <= n; ++i) if (d[i] != -1) {
			for (int j = d[i]; j <= t; ++j) r[j] = i;
			t = std::min(t, d[i] - 1);
		}
		for (int i = 1; i <= n; ++i) std::cout << r[i] << " ";
		println;
	}
	return 0;
}