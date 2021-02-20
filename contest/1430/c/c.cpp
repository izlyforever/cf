#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		print(2);
		if (n == 2) print("1 2");
		else {
			std::cout << n - 2 << " " << n << std::endl;
			std::cout << n - 1 << " " << n - 1 << std::endl;
			int now = n - 1;
			while (now > 2) {
				std::cout << now - 2 << " " << now << std::endl;
				--now;
			}
		}
	}
	return 0;
}