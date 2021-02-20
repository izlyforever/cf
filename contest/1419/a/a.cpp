#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::string a;
		std::cin >> n >> a;
		if (n % 2 == 0) {
			int flag = 1;
			for (int i = 1; i < n; i += 2) if ((a[i] - '0') % 2 == 0) flag = 2; 
			print(flag);
		} else {
			int flag = 2;
			for (int i = 0; i < n; i += 2) if ((a[i] - '0') % 2 == 1) flag = 1;
			print(flag);
		}
	}
	return 0;
}