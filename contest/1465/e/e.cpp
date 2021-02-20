#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	LL s;
	std::string a;
	std::cin >> n >> s >> a;
	s -= 1 << (a.back() - 'a');
	a.pop_back();
	s += 1 << (a.back() - 'a');
	a.pop_back();
	s = abs(s);
	LL cnt[26]{};
	for (auto x : a) ++cnt[x - 'a'];
	for (int i = 25; i >= 0; --i) {
		if ((s >> i) >= cnt[i]) s -= cnt[i] << i;
		else {
			int t = cnt[i] - (s >> i);
			s -= (s >> i) << i;
			if (t % 2) s = (1 << i) - s;
		}
	}
	std::cout << (s == 0 ? "Yes" : "No") << std::endl;
	return 0;
}