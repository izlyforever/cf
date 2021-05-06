#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// fa 里面存编号会导致更新时儿子节点无法追踪到新的父节点。
class PstSegTree {
	struct Node {
		int l, r, fa, dep;
	};
	int newNode() {
		int sz = tree.size();
		tree.emplace_back(Node());
		return sz;
	}
	std::vector<Node> tree;
	int n;
public:
	std::vector<int> root;
	PstSegTree(int _n) : n(_n) {
		std::function<void(int, int, int)> build = [&](int l, int r, int p) {
			if (r - l == 1) {
				tree[p].fa = l;
				tree[p].dep = 0;
			} else {
				int m = (l + r) / 2;
				build(l, m, tree[p].l = newNode());
				build(m, r, tree[p].r = newNode());
			}
		};
		root.emplace_back(newNode());
		build(0, n, root.back());
	}
	int query(int x, int l, int r, int p) {
		if (r - l == 1) return p;
		int m = (l + r) / 2;
		if (x < m) return query(x, l, m, tree[p].l);
		return query(x, m, r, tree[p].r);
	}
	int find(int x, int p) {
		int fx = tree[query(x, 0, n, p)].fa;
		if (fx == x) return x;
		return find(fx, p);
	}
	int queryDep(int x, int p) {
		return tree[query(x, 0, n, p)].dep;
	}
	void update(int x, int fx, int l, int r, int p, int q) {
		if (r - l == 1) {
			tree[q].fa = fx;
			tree[q].dep = tree[p].dep;
		} else {
			int m = (l + r) / 2;
			if (x < m) tree[q].r = tree[p].r, update(x, fx, l, m, tree[p].l, tree[q].l = newNode());
			else tree[q].l = tree[p].l, update(x, fx, m, r, tree[p].r, tree[q].r = newNode());
		}
	}
	void update(int x, int l, int r, int p, int q) {
		if (r - l == 1) {
			tree[q].fa = tree[p].fa;
			tree[q].dep = tree[p].dep + 1;
		} else {
			int m = (l + r) / 2;
			if (x < m) tree[q].r = tree[p].r, update(x, l, m, tree[p].l, tree[q].l = newNode());
			else tree[q].l = tree[p].l, update(x, m, r, tree[p].r, tree[q].r = newNode());
		}
	}
	void merge(int x, int y, int l, int r, int p) {
		x = find(x, p), y = find(y, p);
		if (x != y) {
			int dx = queryDep(x, p), dy = queryDep(y, p);
			if (dx > dy) std::swap(x, y);
			root.emplace_back(newNode());
			if (tree[x].dep != tree[y].dep) {
				update(x, y, 0, n, p, root.back());
			} else {
				// 更新高度需要重开节点，不然高度就不正确（虽然不影响结果是否正确）
				update(y, 0, n, p, root.back());
				p = root.back();
				root.emplace_back(newNode());
				update(x, y, 0, n, p, root.back());
				p = root.back();
				root.pop_back();
				root.back() = p;
			}
		} else root.emplace_back(root.back());
	}
};

int main() {
	// freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, q;
	std::cin >> n >> q;
	PstSegTree A(n);
	while (q--) {
		int op;
		std::cin >> op;
		if (op == 2) {
			int k;
			std::cin >> k;
			A.root.emplace_back(A.root[k]);
		} else {
			int a, b;
			std::cin >> a >> b;
			--a; --b;
			if (op == 1) {
				A.merge(a, b, 0, n, A.root.back());
			} else {
				int fa = A.find(a, A.root.back());
				int fb = A.find(b, A.root.back());
				std::cout << (fa == fb ? 1 : 0) << '\n';
				A.root.emplace_back(A.root.back());
			}
		}
	}
	return 0;
}