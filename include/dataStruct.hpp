#pragma once
#include <bits/stdc++.h>

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

// 线段树（延迟更新，左开右闭）
class SegmentTree {
	int n;
	std::vector<int> mn, tag;
	std::vector<LL> sm;
	#define lson l, m, 2 * p
	#define rson m + 1, r, 2 * p + 1
		void pull(int p) {
		mn[p] = std::min(mn[2 * p], mn[2 * p + 1]);
		sm[p] = sm[2 * p] + sm[2 * p + 1];
	}
	void push(int l, int r, int p) {
		if (tag[p]) {
			int m = (l + r) / 2;
			set(lson, tag[p]);
			set(rson, tag[p]);
			tag[p] = 0;
		}
	}
	void set(int l, int r, int p, int v) {
		tag[p] = mn[p] = v;
		sm[p] = LL(r - l + 1) * v;
	}
	void rangeSet(int L, int R, int v, int l, int r, int p) {
		if (L <= l && R >= r) {
			set(l, r, p, v);
			return;
		}
		int m = (l + r) / 2;
		push(l, r, p);
		if (L <= m) rangeSet(L, R, v, lson);
		if (R > m) rangeSet(L, R, v, rson);
		pull(p);
	}
	// 以下内容根据需要修改
	int query(int x, int& y, int l, int r, int p) {
		if (mn[p] > y) return 0;
		if (x <= l && sm[p] <= y) {
			y -= sm[p];
			return r - l + 1;
		}
		int m = (l + r) / 2;
		push(l, r, p);
		int ans = 0;
		if (x <= m) ans += query(x, y, lson); 
		ans += query(x, y, rson);
		return ans;
	}
	int bounded(int v, int l, int r, int p) {
		if (mn[p] >= v) return r + 1;
		if (l == r) return l;
		int m = (l + r) / 2;
		if (mn[2 * p] >= v) return bounded(v, rson);
		return bounded(v, lson);
	}
	void resize() {
		mn.resize(4 * n);
		tag.resize(4 * n);
		sm.resize(4 * n);
	}
public:
	SegmentTree(int _n) : n(_n) {
		resize();
	}
	SegmentTree(const std::vector<int> &a) {
		n = a.size();
		resize();
		std::function<void(int, int, int)> build = [&](int l, int r, int p) {
			if (l == r) {
				mn[p] = sm[p] = a[l - 1];
				return;
			}
			int m = (l + r) / 2;
			build(lson);
			build(rson);
			pull(p);
		};
		build(1, n, 1);
	}
	void modify(int x, int y) {
		int l = bounded(y, 1, n, 1);
		if (l <= x) rangeSet(l, x, y, 1, n, 1);
	}
	int query(int x, int y) {
		return query(x, y, 1, n, 1);
	}
};

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