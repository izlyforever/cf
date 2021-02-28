#pragma once
#include <bits/stdc++.h>

// a 单调递增，且最大值小于 mx。a 变成下一个字典序大于自身的序列
bool next(std::vector<int> &a, int mx) {
	int n = a.size(), i = 1;
	while (i <= n && a[n - i] == mx - i) ++i;
	if (i > n) return false;
	++a[n - i];
	for (int j = 1; j < i; ++j) {
		a[n - j] = a[n - i] + (i - j);
	}
	return true;
}
// next 应用：暴力枚举，个数为 binom{mx}{n}
void bruteForce(int n, int mx) {
	std::vector<int> a(n);
	std::iota(a.begin(), a.end(), 0);
	do {
		for (auto x : a) std::cout << " ";
		std::cout << "\n";
	} while (next(a, mx));
}

// 纠错码 O(n m + k^k n)，目前不知道怎么优化到 O(n m + k^k \sqrt{nm})
class ECC {
	std::vector<std::vector<int>> a; // 原始数据 n 个 m 维向量
	int k; // 容许的最大不同个数
	std::vector<std::vector<int>> bad; // 与 r 不同的个数
	int n, m, mxId;
	void updateMxId(int i) { if (bad[i].size() > bad[mxId].size()) mxId = i;}
	bool dfs(int c) { // 当前 r 剩余可改变的次数
		auto bd = bad[mxId];
		if (bd.size() <= k) return true;
		if (bd.size() - k > c) return false;
		// 注意到此时 bd 是 O(k) 的而不是 O(m) 的
		std::vector<int> f(bd.size() - k);
		iota(f.begin(), f.end(), 0);
		int tMxId = mxId;
		do {
			mxId = tMxId;
			std::queue<int> tmp;
			for (auto x : f) {
				tmp.push(r[bd[x]]);
				for (int i = 0; i < n; ++i) {
					if (a[i][bd[x]] == r[bd[x]]) {
						bad[i].emplace_back(bd[x]);
					}
					if (a[i][bd[x]] == a[mxId][bd[x]]) {
						bad[i].erase(std::find(bad[i].begin(), bad[i].end(), bd[x]));
					}
				}
				r[bd[x]] = a[mxId][bd[x]];
			}
			for (int i = 0; i < n; ++i) updateMxId(i);
			if (dfs(c - f.size())) return true;
			for (auto x : f) {
				for (int i = 0; i < n; ++i) {
					if (a[i][bd[x]] == r[bd[x]]) {
						bad[i].emplace_back(bd[x]);
					}
					if (a[i][bd[x]] == tmp.front()) {
						bad[i].erase(std::find(bad[i].begin(), bad[i].end(), bd[x]));
					}
				}
				r[bd[x]] = tmp.front();
				tmp.pop();
			}
		} while (next(f, bd.size()));
		return false;
	}
public:
	std::vector<int> r; // m 维向量，表示当前答案
	ECC(std::vector<std::vector<int>> _a) : a(_a), r(a[0]) {
		n = a.size(); m = r.size();
		bad.resize(n);
		mxId = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) if (a[i][j] != r[j]) {
				bad[i].emplace_back(j);
			}
			updateMxId(i);
		}
	}
	void setK(int _k) { k = _k;}
	bool solve() { return dfs(k);}
};

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
	return r;
}

// 并查集 Disjoint Set Union
class DSU {
	std::vector<int> p;
public:
	DSU(int n) : p(n) {
		iota(p.begin(), p.end(), 0);
	}
	int find(int x) {
		if (x != p[x]) x = find(p[x]);
		return p[x];
	}
	void merge(int x, int y) {
		int px = find(x), py = find(y);
		if (px == py) return;
		// do something, small to big;
	}
};

// 最小值树状数组（单点更新，从 最左边 到某个位置的最小值）
struct TreeArrayMin {
	std::vector<int> s;
	TreeArrayMin() {}
	TreeArrayMin(int n) : s(n + 1, INT_MAX) {}
	int lowbit(int n) { 
		return n & (-n);
	}
	void modify(int id, int p) {
		while (id < s.size()) {
			s[id] = std::min(s[id], p);
			id += lowbit(id);
		}
	}
	// 计算区间 [1, id] 的最小值
	int min(int id) {
		int r = INT_MAX;
		while (id) {
			r = std::min(r, s[id]);
			id -= lowbit(id);
		}
		return r;
	}
};

// 常规树状数组（编号从 1 开始，单点更新，区间求和，提供搜索）
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
	// find minimal index s.t. sum(id) >= x, sum must be increased
	int search(LL val) {
		LL sum = 0;
		int id = 0;
		for (int i = std::__lg(s.size()); ~i; --i) {
			if (id + (1 << i) < s.size() && sum + s[id + (1 << i)] < val) {
				id += (1 << i);
				sum += s[id];
			}
		}
		return ++id;
	}
};

// 加强版树状数组（编号从 1 开始，区间更新，区间求和）
class TreeArrayPlus {
	int n;
	// c[i] = a[i] - a[i - 1], b_i = (i - 1) * c_i
	TreeArray B, C;
	void add(int id, int p) {
		C.add(id, p);
		B.add(id, (id - 1) * p);
	}
public:
	TreeArrayPlus() {}
	TreeArrayPlus(int _n) : n(_n), B(n), C(n) {}
	void add(int l, int r, int p) {
		add(l, p);
		add(r + 1, -p);
	}
	LL sum(int id) {
		return id * C.sum(id) - B.sum(id);
	}
	LL sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	// find minimal index s.t. sum(id) >= x, sum must be increased
	int search(LL val) {
		LL sumB = 0, sumC = 0;
		int id = 0;
		for (int i = std::__lg(n); ~i; --i) if (int idi = id + (1 << i); idi <= n) {
			if (idi * (sumC +  C.s[idi]) - B.s[idi] - sumB < val) {
				id = idi;
				sumB += B.s[id];
				sumC += C.s[id];
			}
		}
		return ++id;
	}
};

// 最简单的延迟更新求和版本，其它的根据需求修改即可
class SegmentTree {
	int n;
	std::vector<LL> sm, tag;
	#define lsonST l, m, 2 * p
	#define rsonST m + 1, r, 2 * p + 1
	void pull(int p) {
		sm[p] = sm[2 * p] + sm[2 * p + 1];
	}
	void tagAdd(LL v, int l, int r, int p) {
		tag[p] += v;
		sm[p] += v * (r - l + 1);
	}
	void push(int l, int r, int p) {
		if (tag[p]) {
			int m = (l + r) / 2;
			tagAdd(tag[p], lsonST);
			tagAdd(tag[p], rsonST);
			tag[p] = 0;
		}
	}
	void rangeAdd(int L, int R, LL v, int l, int r, int p) {
		if (L <= l && R >= r) {
			tagAdd(v, l, r, p);
			return;
		}
		push(l, r, p);
		int m = (l + r) / 2;
		if (L <= m) rangeAdd(L, R, v, lsonST);
		if (R > m) rangeAdd(L, R, v, rsonST);
		pull(p);
	}
	// 以下内容根据需要修改
	LL query(int L, int R, int l, int r, int p) {
		if (L <= l && R >= r) return sm[p];
		push(l, r, p);
		int m = (l + r) / 2;
		LL ans = 0;
		if (L <= m) ans += query(L, R, lsonST);
		if (R > m) ans += query(L, R, rsonST);
		return ans;
	}
	void resize() {
		tag.resize(4 * n);
		sm.resize(4 * n);
	}
public:
	SegmentTree(int _n) : n(_n) {
		resize();
	}
	SegmentTree(const std::vector<LL> &a) {
		n = a.size();
		resize();
		std::function<void(int, int, int)> build = [&](int l, int r, int p) {
			if (l == r) {
				sm[p] = a[l - 1];
				return;
			}
			int m = (l + r) / 2;
			build(lsonST);
			build(rsonST);
			pull(p);
		};
		build(1, n, 1);
	}
	void add(int L, int R, LL v) {
		rangeAdd(L, R, v, 1, n, 1);
	}
	LL query(int L, int R) {
		return query(L, R, 1, n, 1);
	}
};
// 模板例题：https://www.luogu.com.cn/problem/P3372

// 最长（严格）递增子序列
int LIS(std::vector<int>& a) { // length of longest increasing subsquence
	std::vector<int> b;
	for (auto x : a) {
		if (auto it = std::lower_bound(b.begin(), b.end(), x); it == b.end()) {
			b.emplace_back(x);
		} else *it = x;
	}
	return b.size();
}
int LNDS(std::vector<int>& a) { // length of longest increasing subsquence
	std::vector<int> b;
	for (auto x : a) {
		if (auto it = std::upper_bound(b.begin(), b.end(), x); it == b.end()) {
			b.emplace_back(x);
		} else *it = x;
	}
	return b.size();
}
auto LISP(std::vector<int>& a) { // longest increasing subsquence
	std::vector<int> b, pb, pa(a.size());
	std::iota(pa.begin(), pa.end(), 0);
	for (int i = 0; i != a.size(); ++i) {
		if (auto it = std::upper_bound(b.begin(), b.end(), a[i]); it == b.end()) {
			if (!pb.empty()) pa[i] = pb.back();
			b.emplace_back(a[i]);
			pb.emplace_back(i);
		} else {
			*it = a[i];
			int t = it - b.begin();
			pb[t] = i;
			if (t > 0) pa[i] = pb[t - 1];
		}
	}
	std::stack<int> c;
	int now = pb.back();
	c.push(a[now]);
	while (now != pa[now]) {
		now = pa[now];
		c.push(a[now]);
	}
	return c;
}
// lower_bound(first,end,val) 表示在单增 [frist,end) 中首次大于等于 val 的位置
// upper_bound(first,end,val) 表示在单增 [frist,end) 中首次大于 val 的位置

// 单调队列
// 求每个长度为 m 的区间最大值的编号
std::vector<int> monicDequeMax(std::vector<int> &a, int m) {
	std::vector<int> r;
	std::deque<int> Q;
	for (int i = 0; i < a.size(); ++i) {
		if (!Q.empty() && i - Q.front() >= m) Q.pop_front();
		// 如果求最小值，大于号改成小于号即可
		while (!Q.empty() && a[i] > a[Q.back()]) Q.pop_back();
		Q.push_back(i);
		// 如果需要返回值，就在下面加入 a[Q.front()]
		if (i >= m - 1) r.emplace_back(Q.front());
	}
	return r;
}

// 单调栈 f(i) 代表数列中第 i 个元素之后第一个大于 a_i 的下标
std::vector<int> monicStack(const std::vector<int> &a) {
	int n = a.size();
	std::vector<int> f(n);
	std::stack<int> S;
	for (int i = 0; i < n; ++i) {
		while (!S.empty() && a[S.top()] < a[i]) {
			f[S.top()] = i;
			S.pop();
		}
		S.push(i);
	}
	return f;
}
// 模板例题：https://www.luogu.com.cn/problem/P5788

// 笛卡尔树
struct cNode {
	int id, val, par, ch[2];
	void init(int _id, int _val, int _par) {
		id = _id, val = _val, par = _par, ch[0] = ch[1] = 0;
	}
};
int cartesian_build(std::vector<cNode> &tree, int n) {
	for (int i = 1; i <= n; ++i) {
		int k = i - 1;
		while (tree[k].val < tree[i].val) k = tree[k].par;
		tree[i].ch[0] = tree[k].ch[1];
		tree[k].ch[1] = i;
		tree[i].par = k;
		tree[tree[i].ch[0]].par = i;
	}
	return tree[0].ch[1];
}
// 模板例题：https://codeforces.com/contest/1490/problem/D

// 三维偏序之陈丹琪分治
struct cdqNode {
	int x, y, z, id, w;
	bool operator<(const cdqNode &A) const {
		if (x == A.x) return y == A.y ? z < A.z : y < A.y;
		return x < A.x;
	}
};
// ans[i] 表示 小于或等于 a[i] 的元素个数
std::vector<int> cdq(std::vector<cdqNode> &a, int k) {
	// 先按照 y 排序，免得后面代码写的太麻烦
	std::vector<int> ans(a.size());
	std::sort(a.begin(), a.end());
	// 去重操作
	int last = 0;
	for (int i = 1; i < a.size(); ++i) {
		if (a[i].x != a[i - 1].x || a[i].y != a[i - 1].y || a[i].z != a[i - 1].z) {
			int t = i - last - 1;
			for (int j = last; j < i; ++j) {
				ans[a[j].id] = t;
				a[j].w = 0;
			}
			a[i - 1].w = i - last;
			last = i;
		}
	}
	int t = a.size() - last - 1;
	for (int i = last; i < a.size(); ++i) {
		ans[a[i].id] = t;
		a[i].w = 0;
	}
	a.back().w = a.size() - last;
	TreeArray A(k);
	auto cmpy = [](const cdqNode &lhs, const cdqNode &rhs) {
		return lhs.y < rhs.y;
	};
	std::function<void(int, int)> divide = [&](int l, int r) {
		if (r - l <= 1) return;
		int m = (l + r) / 2;
		divide(l, m);
		divide(m, r);
		std::sort(a.begin() + l, a.begin() + m, cmpy);
		std::sort(a.begin() + m, a.begin() + r, cmpy);
		int t = l;
		for (int i = m; i < r; ++i) {
			while (t < m && a[t].y <= a[i].y) {
				A.add(a[t].z, a[t].w);
				++t;
			}
			ans[a[i].id] += A.sum(a[i].z);
		}
		for (int i = l; i < t; ++i) A.add(a[i].z, -a[i].w);
	};
	divide(0, a.size());
	return ans;
}
// 模板例题：https://www.luogu.com.cn/problem/P3810