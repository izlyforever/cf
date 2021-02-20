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
	print((n - 1) / 2);
	int l = 0, r = n - 1;
	while (l < r) {
		std::cout << a[r] << " " << a[l] << " ";
		++l; --r;
	}
	if (l == r) std::cout << a[l] <<" ";
	std::cout << std::endl;
	return 0;
}