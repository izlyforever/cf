#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

namespace NFT {
LL M = 998244353, ROOT = 3;
void setM(LL _m, LL _root) {
	M = _m; ROOT = _root;
}
LL powMod(LL x, LL n) {
	LL r(1);
	while (n) {
		if (n & 1) r = r * x % M;
		n >>= 1;
		x = x * x % M;
	}
	return r;
}
std::vector<int> rev;
void bitreverse(std::vector<LL> &a) {
	// 注释部分被淘汰了
	// for (int i = 0, j = 0; i != a.size(); ++i) {
	// 	if (i > j) std::swap(a[i], a[j]);
	// 	for (int l = a.size() >> 1; (j ^= l) < l; l >>= 1);
	// }
	int n = a.size();
	if (n != rev.size()) {
		int k = __builtin_ctz(n) - 1;
		rev.resize(n);
		for (int i = 0; i < n; ++i) {
			rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
		}
	}
	for (int i = 0; i < n; ++i) if (rev[i] < i) {
		std::swap(a[i], a[rev[i]]);
	}
}
void nft(std::vector<LL> &a, bool isInverse = false) {
	LL g = powMod(ROOT, (M - 1) / a.size());
	if (isInverse) {
		g = powMod(g, M - 2);
		LL invLen = powMod(LL(a.size()), M - 2);
		for (auto & x: a) x = x * invLen % M;
	}
	bitreverse(a);
	std::vector<LL> w(a.size(), 1);
	for (int i = 1; i != w.size(); ++i) w[i] = w[i - 1] * g % M;
	auto addMod = [](LL x, LL y) {
		return (x += y) >= M ? x -= M : x;
	};
	for (int step = 2, half = 1; half != a.size(); step <<= 1, half <<= 1) {
		for (int i = 0, wstep = a.size() / step; i != a.size(); i += step) {
			for (int j = i; j != i + half; ++j) {
				LL t = (a[j + half] * w[wstep * (j - i)]) % M;
				a[j + half] = addMod(a[j], M - t);
				a[j] = addMod(a[j], t);
			}
		}
	}
}
void mul(std::vector<LL>& a, std::vector<LL> b) {
	int n = a.size(), m = b.size(), tot = n + m - 1;
	if (n < 8 || m < 8 || tot < 64) {
		std::vector<LL> c(tot);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++ j) {
				c[i + j] += a[i] * b[j] % M;
			}
			for (auto &x : c) x %= M;
		}
		std::swap(a, c);
		return;
	}
	int sz = 1 << int(std::__lg(tot - 1) + 1);
	a.resize(sz);
	b.resize(sz);
	nft(a);
	nft(b);
	for (int i = 0; i != sz; ++i) a[i] = a[i] * b[i] % M;
	nft(a, 1);
	a.resize(tot);
}
// 上面是（加法）卷积，下面是减法卷积
void mult(std::vector<LL> &a, std::vector<LL> b) {
	int n = a.size();
	std::reverse(a.begin(), a.end());
	NFT::mul(a, b);
	a.resize(n);
	std::reverse(a.begin(), a.end());
}
// 递归版本
std::vector<LL> inv(std::vector<LL> a, int n) {
	if (n == 1) return std::vector<LL>({powMod(a[0], M - 2)});
	std::vector<LL> invA(n), b = inv(a, (n + 1) / 2);
	a.resize(n); mul(a, b); a.resize(n);
	invA[0] = (M + 2 - a[0]) % M;
	for (int i = 1; i < n; ++i) invA[i] = (a[i] == 0 ? 0 : M - a[i]);
	mul(invA, b); invA.resize(n);
	return std::move(invA);
}
// 非递归版本实测要慢一些（不敢相信）
std::vector<LL> invS(std::vector<LL> a, int n) {
	assert(a[0] != 0);
	std::vector<LL> invA({powMod(a[0], M - 2)});
	for (int sz = 1; sz < n; sz *= 2) {
		auto aa = a;
		aa.resize(2 * sz);
		mul(aa, invA);
		std::vector<LL> invAA(2 * sz);
		invAA[0] = (M + 2 - aa[0]) % M;
		for (int i = 1; i < 2 * sz; ++i) invAA[i] = (aa[i] == 0 ? 0 : M - aa[i]);
		mul(invAA, invA);
		invAA.resize(2 * sz);
		std::swap(invAA, invA);
	}
	return std::move(invA);
}
// 多点求值新科技：https://jkloverdcoi.github.io/2020/08/04/转置原理及其应用/
std::vector<LL> multiValue(std::vector<LL> f, std::vector<LL> a) {
	int n = a.size(), sz = f.size();
	std::vector<std::vector<LL>> g(4 * n), ans(4 * n);
	std::vector<LL> ret(n);
	auto pushUp = [&](int rt) {
		g[rt] = g[rt * 2];
		mul(g[rt], g[rt * 2 + 1]);
	};
	std::function<void(int, int, int)> build = [&](int l, int r, int rt) {
		if (l == r) {
			g[rt] = {1, (a[l - 1] == 0 ? 0 :M - a[l - 1])};
			return;
		}
		int m = (l + r) / 2;
		build(l, m, rt * 2);
		build(m + 1, r, rt * 2 + 1);
		pushUp(rt);
	};
	auto pushDown = [&](int l, int r, int rt) {
		int m = (l + r) / 2, lm = m - l + 1, rm = r - m;
		ans[rt * 2] = ans[rt * 2 + 1] = ans[rt];
		mult(ans[rt * 2], g[rt * 2 + 1]);
		ans[rt * 2].resize(lm);
		mult(ans[rt * 2 + 1], g[rt * 2]);
		ans[rt * 2 + 1].resize(rm);
	};
	std::function<void(int, int, int)> solve = [&](int l, int r, int rt) {
		if (l == r) {
			ret[l - 1] = ans[rt].back();
			return;
		}
		pushDown(l, r, rt);
		int m = (l + r) / 2;
		solve(l, m, rt * 2);
		solve(m + 1, r, rt * 2 + 1);
	};
	build(1, n, 1);
	ans[1] = f;
	mult(ans[1], inv(g[1], sz));
	ans[1].resize(sz);
	solve(1, n, 1);
	return ret;
}
// 模板例题：https://www.luogu.com.cn/problem/P5050

// \sum_{i = 0}^{n - 1} a_i / (1 - b_i x)
std::vector<LL> sumFraction(std::vector<LL> a, std::vector<LL> b, int N) {
	std::function<std::pair<std::vector<LL>, std::vector<LL>>(int, int)> solve = [&](int l, int r) {
		if (l == r) {
			return std::make_pair(std::vector<LL>({a[l - 1]}), std::vector<LL>({1, (b[l - 1] == 0 ? 0 : M - b[l - 1])}));
		}
		int m = (l + r) / 2;
		auto [pl, ql] = solve(l, m);
		auto [pr, qr] = solve(m + 1, r);
		auto p = pl, q = pr;
		mul(p, qr); mul(q, ql);
		for (int i = 0; i < p.size(); ++i) if ((p[i] += q[i]) >= M) p[i] -= M;
		q = ql; mul(q, qr);
		return std::make_pair(p, q);
	};
	auto [p, q] = solve(1, a.size());
	mul(p, inv(q, N));
	p.resize(N);
	return p;
}
} // namespace NFT

const LL M = 998244353;

int main() {
	// freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<LL> a(n), b(n), c(n);
	for (auto &x : a) std::cin >> x;
	for (auto &x : b) std::cin >> x;
	for (auto &x : c) std::cin >> x;
	std::vector<std::vector<LL>> g(4 * n), h(4 * n);
	int id = 0;
	std::function<void(int, int, int)> build = [&](int l, int r, int rt) {
		if (l == r) {
			g[rt] = {b[l - 1], 1};
			return;
		}
		int m = (l + r) / 2;
		build(l, m, rt * 2);
		build(m + 1, r, rt * 2 + 1);

		g[rt] = g[rt * 2];
		NFT::mul(g[rt], g[rt * 2 + 1]);
	};
	std::function<void(int, int, int)> solve = [&](int l, int r, int rt) {
		if (l == r) {
			std::cout << (h[rt][0] * b[l - 1] + h[rt][1]) % M << " \n"[r == n];
			return;
		}
		int m = (l + r) / 2;
		h[rt * 2] = h[rt * 2 + 1] = h[rt];
		h[rt * 2].resize(m - l + 2);
		NFT::mult(h[rt * 2 + 1], g[rt * 2]);
		h[rt * 2 + 1].resize(r - m + 1);

		solve(l, m, rt * 2);
		solve(m + 1, r, rt * 2 + 1);
	};
	build(1, n, 1);
	h[1] = NFT::sumFraction(c, a, n + 1);
	solve(1, n, 1);
	return 0;
}