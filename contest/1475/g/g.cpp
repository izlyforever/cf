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
		std::vector<int> a(n), r(n);
		for (auto &x : a) std::cin >> x;
		std::sort(a.rbegin(), a.rend());
		int mx = a[0];
		std::vector<int> mp(2e5 + 2, -1);
		for (int i = 0; i < n; ++i) {
			if (mp[a[i]] != -1) {
				r[i] = r[mp[a[i]]] + 1;
				mp[a[i]] = i;
				continue;
			}
			for (int j = 2 * a[i]; j <= mx; j += a[i]) if (mp[j] != -1) {
				r[i] = std::max(r[i], r[mp[j]]);
			}
			++r[i];
			mp[a[i]] = i;
		}
		std::cout << (n - *std::max_element(r.begin(), r.end())) << "\n";
	}
	return 0;
}