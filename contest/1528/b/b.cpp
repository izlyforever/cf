#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	const int M = 998244353;
	int n;
	std::cin >> n;
	std::vector<int> d(n + 1), a(n + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; j += i) ++d[j];
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = a[i - 1] * 2;
		if (a[i] >= M) a[i] -= M;
		a[i] += d[i];
		if (a[i] >= M) a[i] -= M;
		a[i] -= d[i - 1];
		if (a[i] < 0) a[i] += M;
	}
	std::cout << a[n] << '\n';
	return 0;
}