#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::string s;
		std::cin >> n >> s;
		int id = 0, r = 0;
		while (id < n) {
			while (id < n && s[id] == s[0]) ++id;
			int tmp = id;
			while (id < n && s[id] != s[0]) ++id;
			if (id > tmp) r += id - tmp - 1; 
		}
		print(r);
	}
	return 0;
}