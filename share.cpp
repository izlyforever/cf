#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// 借鉴了 jiangly 和 Miskcoo 的模板
constexpr int P = 998244353;
std::vector<int> rev, roots{0, 1};
LL powMod(LL x, LL n) {
	LL r(1);
	while (n) {
		if (n & 1) r = r * x % P;
		n >>= 1;
		x = x * x % P;
	}
	return r;
}
void dft(std::vector<LL> &a) {
    int n = a.size();
    if (int(rev.size()) != n) {
        int k = __builtin_ctz(n) - 1;
        rev.resize(n);
        for (int i = 0; i < n; ++i)
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
    }
    for (int i = 0; i < n; ++i)
        if (rev[i] < i)
            std::swap(a[i], a[rev[i]]);
    if (int(roots.size()) < n) {
        int k = __builtin_ctz(roots.size());
        roots.resize(n);
        while ((1 << k) < n) {
            int e = powMod(3, (P - 1) >> (k + 1));
            for (int i = 1 << (k - 1); i < (1 << k); ++i) {
                roots[2 * i] = roots[i];
                roots[2 * i + 1] = 1ll * roots[i] * e % P;
            }
            ++k;
        }
    }
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; ++j) {
                int u = a[i + j];
                int v = 1ll * a[i + j + k] * roots[k + j] % P;
                int x = u + v;
                if (x >= P)
                    x -= P;
                a[i + j] = x;
                x = u - v;
                if (x < 0)
                    x += P;
                a[i + j + k] = x;
            }
        }
    }
}
void idft(std::vector<LL> &a) {
    int n = a.size();
    std::reverse(a.begin() + 1, a.end());
    dft(a);
    int inv = powMod(n, P - 2);
    for (int i = 0; i < n; ++i)
        a[i] = 1ll * a[i] * inv % P;
}

class Poly {
	inline const static LL M = P, inv2 = (M + 1) / 2;
	std::vector<LL> a;
	void standard() {
		while (!a.empty() && !a.back()) a.pop_back();
	}
public:
	Poly() {}
	Poly(LL x) { if (x) a = {x};}
	Poly(const std::vector<LL> _a) : a(_a) { standard();}
	int size() const { return a.size();}
	LL operator[](int id) const {
		if (id < 0 || id > a.size()) return 0;
		return a[id];
	}
	Poly mulXn(int n) const {
		auto b = a;
		b.insert(b.begin(), n, 0);
		return Poly(b);
	}
	Poly modXn(int n) const {
		if (n > size()) return *this;
		return Poly(std::vector<LL>(a.begin(), a.begin() + n));
	}
	Poly divXn(int n) const {
		if (size() <= n) return Poly();
		return Poly(std::vector<LL>(a.begin() + n, a.end()));
	}
	Poly &operator+=(const Poly &A) {
		if (size() < A.size()) a.resize(A.size());
		for (int i = 0; i < A.size(); ++i) {
			if ((a[i] += A.a[i]) >= M) a[i] -= M;
		}
		standard();
		return *this;
	}
	Poly &operator-=(const Poly &rhs) {
		if (size() < rhs.size()) a.resize(rhs.size());
		for (int i = 0; i < rhs.size(); ++i) {
			if ((a[i] -= rhs.a[i]) < 0) a[i] += M;
		}
		standard();
		return *this;
	}
	Poly &operator*=(Poly rhs) {
		int n = size(), m = rhs.size(), tot = n + m - 1, sz = 1;
		// if (n < 8 || m < 8) {
		// 	std::vector<LL> c(tot);
		// 	for (int i = 0; i < n; ++i) {
		// 		for (int j = 0; j < m; ++j) {
		// 			c[i + j] = (c[i + j] + a[i] * rhs.a[j]) % M;
		// 		}
		// 	}
		// 	return *this = Poly(c);
		// }
		while (sz < tot) sz *= 2;
		a.resize(sz);
		rhs.a.resize(sz);
		dft(a);
		dft(rhs.a);
		for (int i = 0; i < sz; ++i) {
			a[i] = a[i] * rhs.a[i] % M;
		}
		idft(a);
		standard();
		return *this;
	}
	Poly operator+(const Poly &rhs) const {
		return Poly(*this) += rhs;
	}
	Poly operator-(const Poly &rhs) const {
		return Poly(*this) -= rhs;
	}
	Poly operator*(Poly rhs) const {
		return Poly(*this) *= rhs;
	}
	Poly derivation() const {
		if (a.empty()) return Poly();
		int n = size();
		std::vector<LL> r(n - 1);
		for (int i = 1; i < n; ++i) r[i - 1] =  a[i] * i % M;
		return Poly(r);
	}
	Poly integral() const {
		if (a.empty()) return Poly();
		int n = size();
		std::vector<LL> r(n + 1), inv(n + 1);
		inv[1] = 1;
		for (int i = 2; i <= n; ++i) inv[i] = (M - M / i) * inv[M % i] % M;
		for (int i = 0; i < n; ++i) r[i + 1] = a[i] * inv[i + 1] % M;
		return Poly(r);
	}
	Poly inv(int n) const {
		Poly x(powMod(a[0], M - 2));
		int k = 1;
		while (k < n) {
			k *= 2;
			x *= (Poly(2) - modXn(k) * x).modXn(k);
		}
		return x.modXn(n);
	}
	Poly log(int n) const {
		return (derivation() * inv(n)).integral().modXn(n);
	}
	Poly exp(int n) const {
		Poly x(1);
		int k = 1;
		while (k < n) {
			k *= 2;
			x = (x * (Poly(1) - x.log(k) + modXn(k))).modXn(k);
		}
		return x.modXn(n);
	}
	Poly sqrt(int n) const {
		Poly x(1);
		int k = 1;
		while (k < n) {
			k *= 2;
			x = (x + (modXn(k) * x.inv(k)).modXn(k) * (inv2 % M));
		}
		return x.modXn(n);
	}
	// 减法卷积
	Poly mulT(Poly rhs) const {
		if (rhs.size() == 0) return Poly();
		int n = rhs.size();
		std::reverse(rhs.a.begin(), rhs.a.end());
		return ((*this) * rhs).divXn(n - 1);
	}
	// 多点求值
	std::vector<LL> eval(std::vector<LL> x) const {
		if (size() == 0) return std::vector<LL>(x.size());
		int n = x.size();
		std::vector<LL> ans(n);
		std::vector<Poly> g(4 * n);
		std::function<void(int, int, int)> build = [&](int l, int r, int p) {
			if (r - l == 1) {
				g[p] = std::vector<LL>{1, (M - x[l]) % M};
			} else {
				int m = (l + r) / 2;
				build(l, m, 2 * p);
				build(m, r, 2 * p + 1);
				g[p] = g[2 * p] * g[2 * p + 1];
			}
		};
		build(0, n, 1);
		std::function<void(int, int, int, const Poly &)> solve = [&](int l, int r, int p, const Poly &f) {
			if (r - l == 1) {
				ans[l] = f[0];
			} else {
				int m = (l + r) / 2;
				solve(l, m, 2 * p, f.mulT(g[2 * p + 1]).modXn(m - l));
				solve(m, r, 2 * p + 1, f.mulT(g[2 * p]).modXn(r - m));
			}
		};
		solve(0, n, 1, mulT(g[1].inv(n)).modXn(n));
		return ans;
	}
	// 计算 \sum_{i = 0}^{n - 1} a_i / (1 - b_i x)
};

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<LL> a(n);
	for (auto &x : a) std::cin >> x;
	Poly A(a);
	auto b = A.inv(n);
	for (int i = 0; i < n; ++i) std::cout << b[i] << " ";
	std::cout << "\n";
	return 0;
}