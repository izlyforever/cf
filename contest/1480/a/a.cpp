#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		std::string s;
		std::cin >> s;
		for (int i = 0; i < s.size(); ++i) {
			if (i & 1) {
				s[i] = (s[i] == 'z' ? 'y' : 'z');
			} else {
				s[i] = (s[i] == 'a' ? 'b' : 'a');
			}
		}
		std::cout << s << "\n";
	}
	return 0;
}