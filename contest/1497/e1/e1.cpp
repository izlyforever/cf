#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	const int N = 1e7 + 2;
	std::vector<int> f(N);
	for (int i = 1; i * i < N; ++i) {
		int ii = i * i, cur = 0;
		for (int j = ii; j < N; j += ii) f[j] = ++cur;
	}
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, k;
		std::cin >> n >> k;
		std::vector<int> a(n);
		for (auto &x : a) {
			std::cin >> x;
			x = f[x];
		}
		int ans = 1;
		std::set<int> S;
		for (int i = 0; i < n; ++i) {
			if (S.count(a[i])) {
				++ans;
				S.clear();
			}
			S.insert(a[i]);
		}
		std::cout << ans << '\n';
	}
	return 0;
}