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
	int a[n + 1], mi = 1;
	for (int i = 2, mx1, mx2; i <= n; ++i) {
		std::cout << "? " << i << " " << mi << std::endl;
		std::cin >> mx1;
		std::cout << "? " << mi << " " << i << std::endl;
		std::cin >> mx2;
		if (mx1 > mx2) {
			a[i] = mx1;
		} else {
			a[mi] = mx2;
			mi = i;
		}
	}
	a[mi] = n;
	std::cout << "!";
	for (int i = 1; i <= n; ++i) std::cout << " " << a[i];
	std::cout << std::endl;
	return 0;
}