#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n), v(n), p(n), id(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i] >> v[i];
	std::iota(p.begin(), p.end(), 0);
	std::sort(p.begin(), p.end(), [&](int i, int j) {
		return a[i] < a[j];
	});
	// 还有不动的点，也太恶心了吧
	// std::deque<int> Q;
	// for (int i = 0; i < n; ++i) {
	// 	int x = p[i];
	// 	if (v[x] == 1) {

	// 	}
	// }
	return 0;
}