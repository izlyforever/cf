#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

struct SegmentTree {
	int n;
	std::vector<int> mn;
	#define lson l, m, 2 * p
	#define rson m + 1, r, 2 * p + 1
	SegmentTree(int _n) : n(_n), mn(4 * n, 0) {}
	void pull(int p) {
		mn[p] = std::min(mn[2 * p], mn[2 * p + 1]);
	}
	void modify(int x, int val, int l, int r, int p) {
		if (l == r) {
			mn[p] = val;
			return;
		}
		int m = (l + r) / 2;
		if (x <= m) modify(x, val, lson);
		else modify(x, val, rson);
		pull(p);
	}
	void modify(int x, int y) {
		modify(x, y, 1, n, 1);
	}
	int query() {
		return mn[1];
	}
};

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	std::cin >> n >> k;
	int cnt = 0;
	SegmentTree A(k);
	LL r = 0;
	for (int i = 1, x; i <= n; ++i) {
		std::cin >> x;
		A.modify(x, i);
		r += A.query();
	}
	std::cout << r << std::endl;
	return 0;
}