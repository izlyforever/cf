#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (auto &x : a) std::cin >> x;
		std::vector<int> b(n + 1, n);
		b[a[0]] = 0;
		for (int i = 1; i < n; ++i) if (a[i] != a[i - 1]) {
			if (b[a[i]] == n) b[a[i]] = 1;
			else ++b[a[i]];
		}
		int ans = n;
		for (int i = 1; i <= n; ++i) if (b[i] != n) {
			if (i != a.back()) ++ b[i];
			ans = std::min(ans, b[i]);
		}
		std::cout << ans << std::endl;
	}
	return 0;
}