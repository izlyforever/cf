#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = __int128;
int N;

// 考虑环 $\mathbb{z}[sqrt{N}]: a + b sqrt{N}$
class SqrtZn {
	static inline int N;
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


namespace int128 {
__int128 read(){
	__int128 x = 0;
	bool negetive = false;
	char ch = getchar();
	while (ch < '0' || ch > '9'){
		if (ch == '-') negetive = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return negetive ?  -x : x;
}
void printS(__int128 x){
	if (x > 9) printS(x / 10);
	putchar(x % 10 + '0');
}
void print(__int128 x){ 
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	printS(x);
}
} // namespace int128


int main() {
	//freopen("in", "r", stdin);
	// std::cin.tie(nullptr)->sync_with_stdio(false);
	SqrtZn::setMod(3);
	SqrtZn A(2, 1);
	LL inf = 1;
	inf <<= 102;
	std::vector<SqrtZn> R;
	auto now = A;
	while (now < inf) {
		R.emplace_back(now);
		now *= A;
	}
	int cas = 1;
	scanf("%d", &cas);
	while (cas--) {
		LL n = int128::read();
		auto ans = *std::lower_bound(R.begin(), R.end(), (n + 1) / 2) * 2;
		int128::print(ans.a);
		printf("\n");
	}
	return 0;
}