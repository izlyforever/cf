#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

class PstDSU {
public:
	int n;
	struct Node {
		int l, r, fa, dep;
	};
	int newNode () {
		int sz = tree.size();
		tree.emplace_back(Node());
		return sz;
	}
	std::vector<Node> tree;
	std::vector<int> root;
	PstDSU(int _n) : n(_n) {
		std::function<void(int, int, int)> build = [&](int l, int r, int p) {
			if (r - l == 1) {
				tree[p].fa = l;
			} else {
				int m = (l + r) / 2;
				build(l, m, tree[p].l = newNode());
				build(m, r, tree[p].r = newNode());
			}
		};
		root.emplace_back(newNode());
		build(0, n, root.back());
	}
	int find(int x, int p) {
		int px = query(x, 0, n, p);
		if (x == px) return x;
		return find(px, p);
	}
	int query(int x, int l, int r, int p) {
		if (r - l == 1) return tree[p].fa;
		int m = (l + r) / 2;
		if (x < m) return query(x, l, m, tree[p].l);
		return query(x, m, r, tree[p].r);
	}
	int queryDep(int x, int l, int r, int p) {
		if (r - l == 1) return tree[p].dep;
		int m = (l + r) / 2;
		if (x < m) return query(x, l, m, tree[p].l);
		return query(x, m, r, tree[p].r);
	}
	void update(int x, int y, int l, int r, int p, int q) {
		tree[q] = tree[p];
		if (r - l == 1) {
			tree[q].fa = y;
		} else {
			int m = (l + r) / 2;
			if (x < m) update(x, y, l, m, tree[p].l, tree[q].l = newNode());
			update(x, y, m, r, tree[p].r, tree[q].r = newNode());
		}
	}
	void merge(int x, int y, int p) {
		int fx = find(x, p), fy = find(y, p);
		if (fx != fy) {
			root.emplace_back(newNode());
			if (tree[fx].dep > tree[fy].dep) {
				update(fy, fx, 0, n, p, root.back());
			} else {
				update(fx, fy, 0, n, p, root.back());
				if (tree[fx].dep == tree[fy].dep) ++tree[fy].dep;
			}
		} else root.emplace_back(root.back());
	}
};

int main() {
	// freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, q;
	std::cin >> n >> q;
	PstDSU A(n);
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
				A.merge(a, b, A.root.back());
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