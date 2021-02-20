#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
// 返回的是离散化之后的数组值对应的原始值

template<typename T>
std::vector<T> discrete(std::vector<T>& a) {
	auto b = a;
	std::sort(b.begin(), b.end());
	b.erase(std::unique(b.begin(), b.end()), b.end());
	std::vector<T> r(b.size());
	for (auto & x : a) {
		int id = std::lower_bound(b.begin(), b.end(), x) - b.begin();
		r[id] = x;
		x = id;
	}
	for (auto &x : a) ++x;
	return r;
}

struct TreeArray {
	std::vector<int> s;
	TreeArray() {}
	TreeArray(int n) { init(n); }
	void init(int n) {
		s.resize(n + 1);
		std::fill(s.begin(), s.end(), 0);
	}
	int lowbit(int n) { 
		return n & (-n);
	}
	void add(int id, int p) {
		while (id < s.size()) {
			s[id] += p;
			id += lowbit(id);
		}
	}
	int sum(int id) {
		int r = 0;
		while (id) {
			r += s[id];
			id -= lowbit(id);
		}
		return r;
	}
};

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<std::pair<int, int>> a(n);
		for (auto &[x, y] : a) std::cin >> x >> y;
		std::sort(a.begin(), a.end());
		std::vector<int> b(2 * n);
		for (int i = 0; i < n; ++i) {
			b[2 * i] = a[i].first * 2;
			b[2 * i + 1] = a[i].second * 2 + 1;
		}
		discrete(b);
		for (int i = 0; i < n; ++i) {
			a[i].first = b[2 * i];
			a[i].second = b[2 * i + 1];
		}
		TreeArray A(2 * n);
		int r = 0;
		for (int i = 0; i < n; ++i) {
			int it = std::lower_bound(a.begin(), a.end(), std::make_pair(b[i * 2 + 1], 0)) - a.begin();
			r = std::max(r, A.sum(b[i * 2]) + it - i);
			A.add(b[i * 2], 1);
			A.add(b[i * 2 + 1], -1);
		}
		std::cout << n - r << std::endl;
	}
	return 0;
}