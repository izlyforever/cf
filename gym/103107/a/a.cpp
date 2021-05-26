#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt,tune=native")

// MoRanSky 的做法
class SegTree {
	int n;
	std::vector<int> mx, And, Or, tag;
	void pushUp(int p) {
		mx[p] = std::max(mx[p << 1], mx[p << 1 | 1]);
		And[p] = And[p << 1] | And[p << 1 | 1];
		Or[p] = Or[p << 1] & Or[p << 1 | 1];
	}
	void pushTag(int p, int val) {
		mx[p] = And[p] = Or[p] = tag[p] = val;
	}
	void pushDown(int p) {
		if (tag[p]) {
			pushTag(p << 1, tag[p]);
			pushTag(p << 1 | 1, tag[p]);
			tag[p] = 0;
		}
	}
	void modify(int L, int R, int val, int l, int r, int p) {
		if (r - l == 1) {
			mx[p] = And[p] = Or[p] = mx[p] & val;
		} else {
			if (L <= l && R >= r) {
				if ((val & And[p]) == And[p]) return;
				if ((val & Or[p]) == val) {
					pushTag(p, val);
					return;
				}
			}
			pushDown(p);
			int m = (l + r) / 2;
			if (L < m) modify(L, R, val, l, m, p << 1);
			if (R > m) modify(L, R, val, m, r, p << 1 | 1);
			pushUp(p);
		}
	}
	void update(int x, int val, int l, int r, int p) {
		if (r - l == 1) {
			mx[p] = And[p] = Or[p] = val;
		} else {
			pushDown(p);
			int m = (l + r) / 2;
			if (x < m) update(x, val, l, m, p << 1);
			else update(x, val, m, r, p << 1 | 1);
			pushUp(p);
		}
	}
	int query(int L, int R, int l, int r, int p) {
		if (L <= l && R >= r) return mx[p];
		pushDown(p);
		int m = (l + r) / 2, ans = INT_MIN;
		if (L < m) ans = std::max(ans, query(L, R, l, m, p << 1));
		if (R > m) ans = std::max(ans, query(L, R, m, r, p << 1 | 1));
		return ans;
	}
public:
	SegTree(std::vector<int> a) : n(a.size()), mx(4 * n), And(4 * n), Or(4 * n), tag(4 * n) {
		std::function<void(int, int, int)> build = [&](int l, int r, int p) {
			if (r - l == 1) {
				mx[p] = And[p] = Or[p] = a[l];
			} else {
				int m = (l + r) / 2;
				build(l, m, p << 1);
				build(m, r, p << 1 | 1);
				pushUp(p);
			}
		};
		build(0, n, 1);
	}
	void modify(int L, int R, int val) { modify(--L, R, val, 0, n, 1);}
	void update(int x, int val) { update(--x, val, 0, n, 1);}
	int query(int L, int R) { return query(--L, R, 0, n, 1);}
};

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (auto &x : a) std::cin >> x;
	SegTree A(a);
	while (m--) {
		std::string s;
		std::cin >> s;
		if (s[0] == 'A') {
			int l, r, val;
			std::cin >> l >> r >> val;
			A.modify(l, r, val);
		} else if (s[0] == 'U') {
			int x, val;
			std::cin >> x >> val;
			A.update(x, val);
		} else {
			int l, r;
			std::cin >> l >> r;
			std::cout << A.query(l, r) << '\n';
		}
	}
	return 0;
}