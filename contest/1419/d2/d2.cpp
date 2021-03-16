#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (auto &x : a) std::cin >> x;
	std::sort(a.begin(), a.end());
	int n2 = n / 2;
	std::vector<int> b;
	for (int i = 0; i < n2; ++i) {
		b.emplace_back(a[n2 + i]);
		b.emplace_back(a[i]);
	}
	if (n & 1) b.emplace_back(a.back());
	int r = 0;
	for (int i = 1; i < n - 1; ++i) if (b[i] < b[i - 1] && b[i] < b[i + 1]) ++r;
	std::cout << r << '\n';
	for (int i = 0; i < n; ++i) std::cout << b[i] << " \n"[i == n - 1];
	return 0;
}