#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> w(n + 1, std::vector<int>(n + 1));
	auto a = w;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			std::cin >> a[i][j];
		}
	}
	auto b = a;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) b[i][j] += b[i][j - 1];
	}
	for (int len = 1; len < n; ++len) {
		for (int i = 1, j = len + 1; j <= n; ++i, ++j) {
			w[i][j] = w[i + 1][j] + b[i][j] - b[i][i];
		}
	}
	std::vector<std::vector<int>> f(m + 1, std::vector<int>(n + 2));
	auto mf = f;
	// mf[i - 1][j] \leq mf[i][j] \leq m[i][j + 1]
	for (int i = 1; i < n; ++i) f[0][i] = 1e9;
	for (int i = 1; i <= m; ++i) {
		mf[i][n + 1] = n;
		for (int j = n; j > 0; --j) {
			f[i][j] = INT_MAX;
			for (int k = std::max(i - 1, mf[i - 1][j]); k < j && k <= mf[i][j + 1]; ++k) {
				if (f[i][j] > f[i - 1][k] + w[k + 1][j]) {
					f[i][j] = f[i - 1][k] + w[k + 1][j];
					mf[i][j] = k;
				}
			}
		}
	}
	std::cout << f[m][n] << "\n";
	return 0;
}