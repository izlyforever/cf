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
		std::string s;
		std::cin >> n >> s;
		int x = std::count(s.begin(), s.end(), '>');
		int y = std::count(s.begin(), s.end(), '<');
		if (x > 0 && y > 0) {
			int r = 0, now = 0;
			s += s;
			while (s[now] != '>') ++now;
			int st = now;
			for (int i = st; i < n + st; ++i) {
				while (i < n + st && s[i] != '-') ++i;
				now = i;
				while (i < n + st && s[i] == '-') ++i;
				r += (i > now ? i - now + 1 : 0);
			}
			print(r);
		} else print(n);
	}
	return 0;
}