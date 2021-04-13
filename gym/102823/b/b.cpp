#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 998244353, ROOT = 3;
LL powMod(LL x, int n) {
	LL r(1);
	while (n) {
		if (n & 1) r = r * x % M;
		n >>= 1;
		x = x * x % M;
	}
	return r;
}
void bitreverse(std::vector<LL> &a) {
	for (int i = 0, j = 0; i != a.size(); ++i) {
		if (i > j) std::swap(a[i], a[j]);
		for (int l = a.size() >> 1;
			(j ^= l) < l; l >>= 1);
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
	int sz = 1, tot = a.size() + b.size() - 1;
	while (sz < tot) sz *= 2;
	a.resize(sz);
	b.resize(sz);
	nft(a);
	nft(b);
	for (int i = 0; i != sz; ++i) a[i] = a[i] * b[i] % M;
	nft(a, 1);
	a.resize(tot);
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	const int N = 1e5 + 2;
	std::vector<LL> inv(N);
	inv[1] = 1;
	for (int i = 2; i < N; ++i) inv[i] = (M - M / i) * inv[M % i] % M;
	int cas = 1;
	std::cin >> cas;
	for (int T = 1; T <= cas; ++T) {
		std::cout << "Case " << T << ": ";
		int n, L, m;
		std::cin >> n >> L >> m;
		std::vector<LL> a(n);
		for (auto &x : a) std::cin >> x;
		std::reverse(a.begin(), a.end());
		std::vector<LL> b(n);
		LL now = 1;
		for (int i = 0; i < n; ++i) {
			b[i] = now;
			now = now * (m + i) % M * inv[i + 1] % M;
		}
		mul(a, b);
		a.resize(n);
		std::fill(b.begin(), b.end(), 0);
		now = 1;
		for (int i = 0; i * L < n; ++i) {
			b[i * L] = (now + M) % M;
			now = -now * (m - i) % M * inv[i + 1] % M;
		}
		mul(a, b);
		a.resize(n);
		// c[i] = a[i] * b[0] + \cdots a[n - 1] * b[n - 1 - i]
		// 令 d[i] = a[n - 1 - i], e[i] = c[n - 1 - i] 则
		// e[i] = d[i] * b[0] + ... + d[0] * b[i]
		std::reverse(a.begin(), a.end());
		for (int i = 0; i < n; ++i) std::cout << a[i] << " ";
		std::cout << "\n";
	}
	return 0;
}