#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

struct TreeArray {
	std::vector<LL> s;
	TreeArray() {}
	TreeArray(int n) : s(n + 1) {}
	int lowbit(int n) { 
		return n & (-n);
	}
	void add(int id, int p) {
		while (id < s.size()) {
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
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<int> h(n), w(n);
	std::vector<std::tuple<int, int, int>> a(n);
	for (auto &x : h) std::cin >> x;
	for (auto &x : w) std::cin >> x;
	for (int i = 0; i < n; ++i) {
		a[i] = {h[i], i + 1, w[i]};
	}
	std::sort(a.rbegin(), a.rend());
	TreeArray A(n);
	LL r = 0;
	for (auto [hi, id, wi] : a) {
		r += A.sum(id) * wi;
		A.add(id, wi);
	}
	std::cout << r << std::endl;
	return 0;
}