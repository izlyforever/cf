#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

std::string solve() {
	std::string a, b;
	std::cin >> a >> b;
	int n = a.size();
	std::string c(n, 'a');
	int df = 0;
	for (int i = 0; i < n; ++i) df += a[i] != b[i];
	int now = 0, cnt = 0;
	while (now < n && abs(cnt) < df) {
		if (a[now] != b[now]) {
			--df;
			int tmp = (a[now] == c[now]) - (b[now] == c[now]);
			if (abs(cnt + tmp) > df) {
				c[now] = 'b';
				tmp = (a[now] == c[now]) - (b[now] == c[now]);
				if (abs(cnt + tmp) > df) {
					c[now] = 'c';
				} else cnt += tmp;
			} else cnt += tmp;
		}
		++now;
	}
	for (int i = now; i < n; ++i) if (a[i] != b[i]) {
		c[i] = (cnt < 0 ? a[i] : b[i]);
	}
	return c;
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	for (int T = 1; T <= cas; ++T) {
		std::cout << "Case " << T << ": " << solve() << "\n";
	}
	return 0;
}