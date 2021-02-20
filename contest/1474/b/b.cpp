#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int N = 3e4 + 9;
bool isp[N];
std::vector<int> p;

void initPrimeP() {
	p.emplace_back(2);
	isp[2] = true;
	for (int i = 3; i < N; i += 2) isp[i] = true;
	for (int i = 3; i < N; i += 2) {
		if (isp[i]) p.emplace_back(i);
		for (int j = 1, t = (N - 1) / i + 1; j != p.size() && p[j] < t; ++j) { // 用除号是防止溢出
			isp[i * p[j]] = false;
			// 不要下面的一步的话，复杂度 O(nloglogn), 但是不用除法，常数小
			if (i % p[j] == 0) break;
		}
	}
}

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	initPrimeP();
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int d;
		std::cin >> d;
		int p1 = *std::lower_bound(p.begin(), p.end(), d + 1);
		int p2 = *std::lower_bound(p.begin(), p.end(), d + p1);
		std::cout << p1 * p2 << std::endl;
	}
	return 0;
}