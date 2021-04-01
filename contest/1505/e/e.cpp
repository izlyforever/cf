#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int h, w;
	std::cin >> h >> w;
	std::vector<std::string> s(h);
	for (auto &x : s) std::cin >> x;
	int r = 0, a = 0, b = 0, dir = 1;
	while (a < h && b < w) {
		if (s[a][b] == '*') ++r;
		int fa = 10, fb = 10;
		for (int i = a + 1; i < h; ++i) if (s[i][b] == '*') {
			fa = i - a;
		}
		for (int j = b + 1; j < w; ++j) if (s[a][j] == '*') {
			fb = j - b;
			break;
		}
		if (fa < fb) {
			a += fa;
			dir = 0;
		} else if (fa > fb) {
			b += fb;
			dir = 1;
		} else {
			if (dir) b += fb;
			else a += fa;
		}
	}
	std::cout << r << '\n';
	return 0;
}