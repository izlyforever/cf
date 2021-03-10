#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int solve() {
	int n;
	std::cin >> n;
	std::vector<int> l(n), r(n), a(n);
	for (auto &x : a) std::cin >> x;
	for (int i = 1; i < n; ++i) if (a[i] > a[i - 1]) {
		l[i] = l[i - 1] + 1;
	}
	for (int i = n - 2; i >= 0; --i) if (a[i] > a[i + 1]) {
		r[i] = r[i + 1] + 1;
	}
	int lx = *std::max_element(l.begin(), l.end());
	int rx = *std::max_element(r.begin(), r.end());
	int mx = std::max(lx, rx);
	if (mx % 2 == 1) return 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (l[i] == mx) ++cnt;
		if (r[i] == mx) ++cnt;
	}
	if (cnt != 2) return 0;
	if (cnt == 2) {
		for (int i = 1; i < n - 1; ++i) if (l[i] == mx && r[i] == mx) return 1;
	}
	return 0;
}

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout << solve() << "\n";
}