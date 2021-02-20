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
		std::string s;
		std::cin >> s;
		int na = 0, nb = 0;
		for (auto x : s) {
			if (x == 'A') {
				++na;
			} else {
				if (na > 0) --na;
				else ++nb;
				if (na == 0) nb = nb & 1;
			}
		}
		print(na + nb);
	}
	return 0;
}