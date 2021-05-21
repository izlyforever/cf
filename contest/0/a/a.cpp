#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
int N;

// 考虑环 $\mathbb{z}[sqrt{N}]: a + b sqrt{N}$
class SqrtZn {
	// static inline int N;
public:
	LL a, b;
	static void setMod(int x) { N = x;}
	SqrtZn() {}
	SqrtZn(LL x, LL y = 0) : a(x), b(y) {}
	SqrtZn operator-() { return SqrtZn(-a, -b);}
	SqrtZn operator+(const SqrtZn &rhs) const { return SqrtZn(a + rhs.a, b + rhs.b);}
	SqrtZn operator-(const SqrtZn &rhs) const { return SqrtZn(a - rhs.a, b - rhs.b);}
	SqrtZn operator*(const SqrtZn &rhs) const { return SqrtZn(a * rhs.a + b * rhs.b * N, a * rhs.b + b * rhs.a);}
	SqrtZn& operator+=(const SqrtZn &rhs) {return *this = SqrtZn(*this) + rhs;}
	SqrtZn& operator-=(const SqrtZn &rhs) {return *this = SqrtZn(*this) - rhs;}
	SqrtZn& operator*=(const SqrtZn &rhs) {return *this = SqrtZn(*this) * rhs;}
	friend SqrtZn pow(SqrtZn A, int n) { // 可能意义不大，因为是指数增加的
		SqrtZn R(1, 0);
		while (n) {
			if (n & 1) R = R * A;
			n >>= 1;   A = A * A;
		}
		return R;
	}
	bool operator<(const SqrtZn &rhs) const { return a < rhs.a;}
};

int main() {
	//freopen("in", "r", stdin);
	// std::cin.tie(nullptr)->sync_with_stdio(false);
	SqrtZn::setMod(48);
	SqrtZn A(7, 1);
	LL inf = 1e18;
	std::vector<SqrtZn> R;
	auto now = SqrtZn(1, 0);
	while (now < inf) {
		now *= A;
		R.emplace_back(now);
	}
	LL n;
	while (std::cin >> n && n) {
		auto ans = *std::upper_bound(R.begin(), R.end(), SqrtZn(4 * n + 3));
		ans *= SqrtZn(7, -1);
		if (ans.a % 4 != 3) ans *= SqrtZn(7, -1);
		std::cout << ans.a / 4 << ' ' << ans.b << '\n';
	}
	return 0;
}