#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	std::cin >> n;
	if (n % 4 > 1) {
		std::cout << "NO\n";
		return 0;
	}
	std::vector<int> a(n);
	int l = 0, r = n - 1;
	while (r - l > 4) {
		a[l] = r;
		a[r] = l + 1;
		++l;
		--r;
	}
	if (r - l == 3) {
		a[l] = l + 3;
		a[l + 1] = l;
		a[l + 2] = l + 2;
		a[l + 3] = l + 1;
	} else if (r - l == 4) {
		a[l] = l + 4;
		a[l + 1] = l + 1;
		a[l + 2] = l + 3;
		a[l + 3] = l;
		a[l + 4] = l + 2;
	}
	std::cout << "YES\n";
	for (auto x : a) std::cout << x << ' ';
	std::cout << '\n';
	return 0;
}