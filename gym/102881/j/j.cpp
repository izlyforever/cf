#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
int main() {
	freopen("abc.in","r",stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	std::string s;
	std::cin >> n >> s;
	int b = std::find(s.begin(), s.end(), 'b') - s.begin();
	std::cout << [&]() {
		if (b == n) {
			for (int i = 1; i < n; ++i) if (s[i] != s[0]) return -1;
			return 0;
		}
		int ca = 0;
		for (int i = 0; i < n; ++i) if (s[i] == 'a') ++ca;
		if (ca == 0 || ca == n - 1) return 0;
		auto f = [&](int x) {
			int r = 0;
			for (int i = 0; i < ca; ++i) if (s[i] != 'a') ++r;
			if (s[ca] == 'c' || ca < x) ++r; 
			return r;
		};
		int r = f(b);
		std::reverse(s.begin(), s.end());
		return std::min(r, f(n - 1 - b));
	}() << std::endl;
	return 0;
}