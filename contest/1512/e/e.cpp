#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, l, r, s;
		std::cin >> n >> l >> r >> s;
		--l;
		int sz = (r - l);
		int ls = (sz + 1) * sz / 2;
		int rs = (n + n - sz + 1) * sz / 2;
		if (s < ls || s > rs) {
			std::cout << -1 << '\n';
		} else {
			std::vector<int> a(n), vis(n + 1, 1);
			for (int i = l, mx = n; i < r; ++i, --mx) {
				a[i] = std::min(s - (r - i) * (r - i - 1) / 2, mx);
				s -= a[i];
			}
			for (int i = l; i < r; ++i) vis[a[i]] = 0;
			for (int i = 0, j = 1; i < l; ++i) {
				while (!vis[j]) ++j;
				a[i] = j;
				vis[j] = 0;
			}
			for (int i = r, j = 1; i < n; ++i) {
				while (!vis[j]) ++j;
				a[i] = j;
				vis[j] = 0;
			}
			for (auto x : a) std::cout << x << ' ';
			std::cout << '\n';
		}
	}
	return 0;
}