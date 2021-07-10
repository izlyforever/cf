#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	std::cin >> n;
	using vt = std::vector<std::tuple<int, int, int>>;
	vt a(n);
	std::vector<double> ans(n);
	int now = 0;
	for (auto &[id, atk, hp] : a) {
		std::cin >> atk >> hp;
		id = now++;
	}
	std::sort(a.begin(), a.end());
	std::function<void(double, int)> f = [&](double x, int i) {
		if (i == n) {
			for (int j = 0; j < n; ++j) if (std::get<2>(a[j]) > 0) {
				ans[std::get<0>(a[j])] += x;
			}
			return;
		}
		if (std::get<2>(a[i]) <= 0) {
			f(x, i + 1);
			return;
		}
		int cnt = 0;
		for (int j = 0; j < n; ++j) if (j != i && std::get<2>(a[j]) > 0) ++cnt;
		if (cnt == 0) {
			if (std::get<2>(a[i]) > 0) ans[std::get<0>(a[i])] += x;
			return;
		}
		x /= cnt;
		for (int j = 0; j < n; ++j) if (j != i && std::get<2>(a[j]) > 0) {
			std::get<2>(a[j]) -= std::get<1>(a[i]);
			std::get<2>(a[i]) -= std::get<1>(a[j]);
			f(x, i + 1);
			std::get<2>(a[j]) += std::get<1>(a[i]);
			std::get<2>(a[i]) += std::get<1>(a[j]);
		}
	};
	do {
		f(1, 0);
	} while (std::next_permutation(a.begin(), a.end()));
	std::cout.precision(12);
	int fac = 1;
	for (int i = 1; i <= n; ++i) fac *= i;
	for (auto x : ans) std::cout << std::fixed << x / fac << std::endl;
	return 0;
}