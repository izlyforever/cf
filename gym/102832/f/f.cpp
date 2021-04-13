#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

class Node {
public:
	inline static const int N = 18;
	int a[N]{};
	Node() {}
	Node(int x) {
		++a[0];
		int now = 0;
		while (x) {
			a[++now] = x & 1;
			x >>= 1;
		}
	}
	Node operator+=(const Node &A) {
		for (int i = 0; i < N; ++i) a[i] += A.a[i];
		return *this;
	}
};
LL deal(const Node & A, const Node & B) {
	LL r = 0;
	for (int i = 1; i < Node::N; ++i) {
		r += (LL(A.a[0] - A.a[i]) * B.a[i] + LL(B.a[0] - B.a[i]) * A.a[i]) << (i - 1);
	}
	return r;
}

// 为了代码简洁，树的编号以 1 开始
LL dsuOnTree(std::vector<std::vector<int>> &e, std::vector<int> &a, int rt = 1) {
	int n = a.size();
	// 预处理出重儿子
	std::vector<int> sz(n), son(n);
	std::function<int(int, int)> pdfs = [&](int u, int fa) -> int {
		sz[u] = 1;
		for (auto v : e[u]) if (v != fa) {
			sz[u] += pdfs(v, u);
			if (sz[v] > sz[son[u]]) son[u] = v;
		}
		return sz[u];
	};
	std::vector<LL> ans(n);
	std::function<std::unordered_map<int, Node>(int, int)> dfs = [&](int u, int fa) -> std::unordered_map<int, Node> {
		if (son[u] == 0) return {{a[u], Node(u)}};
		auto mp = dfs(son[u], u);
		mp[a[u]] += Node(u);
		LL r = 0;
		for (auto v : e[u]) if (v != fa && v != son[u]) {
			auto tmp = dfs(v, u);
			for (auto [i, x] : tmp) {
				if (auto it = mp.find(i ^ a[u]); it != mp.end()) {
					r += deal(it->second, x);
				}
			}
			for (auto [i, x] : tmp) mp[i] += x;
		}
		ans[u] = r;
		return mp;
	};
	pdfs(rt, rt);
	dfs(rt, rt);
	LL r = 0;
	for (int i = 1; i < n; ++i) r += ans[i];
	return r;
}

int main() {
	// freopen("C:\\Users\\dna049\\cf\\in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	std::vector<std::vector<int>> e(n + 1);
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	std::cout << dsuOnTree(e, a) << std::endl;
	return 0;
}