#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

class SegmentTree {
	inline const static int N = 30;
	int n;
	std::vector<int> sm, mn, smn, mcnt, tag;
	std::vector<std::array<int, N>> bits;
	void resize() {
		mn.resize(4 * n);
		sm.resize(4 * n);
		smn.resize(4 * n);
		mcnt.resize(4 * n);
		tag.resize(4 * n);
		bits.resize(4 * n);
	}
	void getBit(int p, int x, int c) {
		auto &it = bits[p];
		int i = 0;
		while (x) {
			it[i] += (x & 1 ? c : 0);
			x >>= 1;
			++i;
		}
	}
	void pushUp(int p) {
		int lp = p << 1, rp = (p << 1 | 1);
		sm[p] = sm[lp] ^ sm[rp];
		for (int i = 0; i < N; ++i) bits[p][i] = bits[lp][i] + bits[rp][i];
		if (mn[lp] > mn[rp]) std::swap(lp, rp);
		mn[p] = mn[lp];
		mcnt[p] = mcnt[lp];
		if (mn[lp] == mn[rp]) {
			smn[p] = std::min(smn[lp], smn[rp]);
			mcnt[p] += mcnt[rp];
		} else {
			smn[p] = std::min(smn[lp], mn[rp]);
		}
	}
	void pushTag(int x, int l, int r, int p) {
		if (mn[p] >= x) return;
		sm[p] ^= (mcnt[p] & 1 ? (mn[p] ^ x) : 0);
		getBit(p, mn[p], -mcnt[p]);
		getBit(p, x, mcnt[p]);
		mn[p] = tag[p] = x;
	}
	void pushDown(int l, int r, int p) {
		if (tag[p]) {
			int m = (l + r) / 2;
			pushTag(tag[p], l, m, p << 1);
			pushTag(tag[p], m, r, p << 1 | 1);
			tag[p] = 0;
		}
	}
public:
	SegmentTree(int _n) : n(_n) {
		resize();
	}
	SegmentTree(const std::vector<int> &a) {
		n = a.size();
		resize();
		std::function<void(int, int, int)> build = [&](int l, int r, int p) {
			if (r - l == 1) {
				sm[p] = mn[p] = a[l];
				smn[p] = INT_MAX;
				mcnt[p] = 1;
				getBit(p, a[l], 1);
			} else {
				int m = (l + r) / 2;
				build(l, m, p << 1);
				build(m, r, p << 1 | 1);
				pushUp(p);
			}
		};
		build(0, n, 1);
	}
	void update(int L, int R, int x, int l, int r, int p) {
		if (x <= mn[p]) return;
		if (L <= l && R >= r && x < smn[p]) {
			pushTag(x, l, r, p);
		} else {
			pushDown(l, r, p);
			int m = (l + r) / 2;
			if (L < m) update(L, R, x, l, m, p << 1); 
			if (R > m) update(L, R, x, m, r, p << 1 | 1);
			pushUp(p);
		}
	}
	int sg(int L, int R, int l, int r, int p) {
		if (L <= l && R >= r) return sm[p];
		pushDown(l, r, p);
		int m = (l + r) / 2, ans = 0;
		if (L < m) ans ^= sg(L, R, l, m, p << 1);
		if (R > m) ans ^= sg(L, R, m, r, p << 1 | 1);
		return ans;
	}
	int query(int L, int R, int i, int l, int r, int p) {
		if (L <= l && R >= r) return bits[p][i];
		pushDown(l, r, p);
		int m = (l + r) / 2, ans = 0;
		if (L < m) ans += query(L, R, i, l, m, p << 1);
		if (R > m) ans += query(L, R, i, m, r, p << 1 | 1);
		return ans;
	}
};

int main() {
	// freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	for (auto &x : a) std::cin >> x;
	SegmentTree A(a);
	while (q--) {
		int op, l, r, x;
		std::cin >> op >> l >> r >> x;
		--l;
		if (op == 1) {
			A.update(l, r, x, 0, n, 1);
		} else {
			int sg = A.sg(l, r, 0, n, 1) ^ x;
			if (sg == 0) {
				std::cout << "0\n";
			} else {
				int i = 31 - __builtin_clz(sg);
				int ans = A.query(l, r, i, 0, n, 1);
				if ((x ^ sg) <= x) ++ans;
				std::cout << ans << "\n";
			}
		}
	}
	return 0;
}