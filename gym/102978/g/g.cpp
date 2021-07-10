#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 998244353;
LL powMod(LL x, LL n) {
	LL r(1);
	while (n) {
		if (n & 1) r = r * x % M;
		n >>= 1; x = x * x % M;
	}
	return r;
}
const LL g = powMod(3, (M - 1) / 7);
const int N = 823543; // pow(7, 7)
LL w[7];
void dft(std::vector<LL> &a) {
	int n = a.size();
	std::vector<LL> b(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			b[i] = (b[i] + w[i * j % n] * a[j]) % M;
		}
	}
	std::swap(a, b);
}
void idft(std::vector<LL> &a) {
	int n = a.size();
	std::vector<LL> b(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			b[i] = (b[i] + w[(n - i) * j % n] * a[j]) % M;
		}
	}
	std::swap(a, b);
	LL invN = powMod(n, M - 2);
	// 这一步可以最后一起做
	for (auto &x : a) x = x * invN % M;
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	w[0] = 1;
	for (int i = 1; i < 7; ++i) w[i] = w[i - 1] * g % M;
	auto f = [&](int x) {
		int r = 0;
		for (int j = 0, t = 1; j < 7; ++j, t *= 7) if (x >> j & 1) r += t;
		return r;
	};
	int n;
	LL K;
	std::cin >> n >> K;
	std::vector<LL> a(N);
	for (int i = 0, x; i < n; ++i) {
		std::cin >> x;
		++a[f(x)];
	}
	for (int i = 1; i < N; i *= 7) {
		for (int j = 0; j < N; j += 7 * i) {
			for (int k = 0; k < i; ++k) {
				std::vector<LL> A(7);
				for (int l = 0; l < 7; ++l) A[l] = a[j + k + i * l];
				dft(A);
				for (int l = 0; l < 7; ++l) a[j + k + i * l] = A[l];
			}
		}
	}
	for (int i = 0; i < N; ++i) a[i] = powMod(a[i], (K - 1) % (M - 1) + 1);
	for (int i = 1; i < N; i *= 7) {
		for (int j = 0; j < N; j += 7 * i) {
			for (int k = 0; k < i; ++k) {
				std::vector<LL> A(7);
				for (int l = 0; l < 7; ++l) A[l] = a[j + k + i * l];
				idft(A);
				for (int l = 0; l < 7; ++l) a[j + k + i * l] = A[l];
			}
		}
	}
	std::cout << a[0] << '\n';
	return 0;
}