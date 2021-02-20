#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	std::sort(a, a + n);
	int b[n], s = n / 2;
	for (int i = 0; 2 * i < n; ++i) {
		b[2 * i] = a[i + s];
	}
	for (int i = 0; 2 * i + 1 < n; ++i) {
		b[2 * i + 1] = a[i];
	}
	int r = 0;
	for (int i = 1; i + 1 < n; ++i)  {
		if (b[i] < b[i - 1] && b[i] < b[i + 1]) ++r;
	}
	print(r);
	for (int i = 0; i < n; ++i) std::cout << b[i] <<" \n"[i == n - 1];
	return 0;
}