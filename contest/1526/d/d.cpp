#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

struct Bitree {
	std::vector<LL> s;
	Bitree() {}
	Bitree(int n) : s(n + 1) {}
	int lowbit(int n) { return n & (-n); }
	void add(int id, int p) {
		int ns = s.size();
		while (id < ns) {
			s[id] += p;
			id += lowbit(id);
		}
	}
	LL sum(int id) {
		LL r = 0;
		while (id) {
			r += s[id];
			id -= lowbit(id);
		}
		return r;
	}
};

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	std::map<char, int> mp{{'A', 0}, {'N', 1}, {'O', 2}, {'T', 3}};
	std::string s("ANOT");
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		std::string a;
		std::cin >> a;
		int n = a.size();
		Bitree A(n);
		for (int i = 0; i < n; ++i) A.add(i + 1, 1);
		std::vector<int> p{0, 1, 2, 3}, cnt(4);
		for (auto x : a) ++cnt[mp[x]];
		auto getAns = [&]() {
			LL ans = 0;
			auto B = A;
			for (auto x : p) {
				for (int i = 0; i < n; ++i) {
					int t = mp[a[i]];
					if (t == x) {
						ans += A.sum(i);
						A.add(i + 1, -1);
					}
				}
			}
			return ans;
		};
		LL mx = -1;
		std::string ans;
		do {
			if (LL t = getAns(); t > mx) {
				mx = t;
				ans.clear();
				for (int i = 0; i < 4; ++i) ans += std::string(cnt[i], s[i]);
			} 
		} while (std::next_permutation(p.begin(), p.end()));
		std::cout << ans << '\n';
	}
	return 0;
}