#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	std::string s;
	std::cin >> n >> k >> s;
	std::string a(1, s[0]);
	for (int i = 1, j = 0; i < n && s[i] <= a[j]; ++i) {
		if (s[i] < a[j]) {
			a += s.substr(i - j, j + 1);
			j = -1;
		}
		if (++j == a.size()) {
			a += a;
			j = 0;
		}
	}
	auto ans = a;
	while (ans.size() < k) ans += a;
	ans.resize(k);
	std::cout << ans << '\n';
	return 0;
}