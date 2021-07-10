#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

void solve() {
	int n, x;
	std::cin >> n >> x;
	std::vector<int> a(n);
	for (auto &x : a) std::cin >> x;
	std::sort(a.begin(), a.end());
	int now = 0;
	for (int i = 0; i < n; ++i) {
		now += a[i];
		if (now == x) {
			if (i + 1 == n) {
				std::cout << "NO\n";
				return;
			} else {
				std::swap(a[i], a.back());
				break;
			}
		}
	}
	std::cout << "YES\n";
	for (auto &x : a) std::cout << x << ' ';
	std::cout << '\n';
}
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		solve();
	}
	return 0;
}