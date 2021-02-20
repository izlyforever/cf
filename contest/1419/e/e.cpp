#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl;
using LL = long long;
 
const int N = 1e5 + 5;
bool isp[N];
std::vector<int> p;
 
int initPrimeP() {
	p.emplace_back(2);
	isp[2] = true;
	for (int i = 3; i < N; i += 2) isp[i] = true;
	int sq = int(std::sqrt(N - 1))|1;
	for (int i = 3; i <= sq; i += 2) if (isp[i]) {
		p.emplace_back(i);
		for (int j = i * i; j < N; j += i << 1) {
			isp[j] = false;
		}
	}
	for (int i = sq + 2; i < N; i += 2) if (isp[i]) p.emplace_back(i);
	return p.size();
}
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	initPrimeP();
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		int nn = n;
		std::vector<std::pair<int, int>> pfactor;
		for (int i = 0; p[i] * p[i] <= nn; ++i) {
			if (nn % p[i] == 0) {
				int np = 0;
				while (nn % p[i] == 0) {
					nn /= p[i];
					++np;
				}
				pfactor.push_back({p[i], np});
			}
		}
		if (nn > 1) pfactor.push_back({nn, 1});
		std::set<int> S;
		S.insert(n);
		std::cout << n << " ";
		for (int i = 0; i < pfactor.size(); ++i) {
			S.insert(pfactor[i].first);
			S.insert(pfactor[i].first * pfactor[(i + 1) % pfactor.size()].first);
		}
		for (int i = 0; i < pfactor.size(); ++i) {
			std::cout << pfactor[i].first << " ";
			int ni = n / pfactor[i].first;
			for (int j = 2; j * j <= ni; ++j) if (ni % j == 0){
				int c[2] = {j * pfactor[i].first, ni / j * pfactor[i].first};
				for (int k = 0; k < 2; ++k) {
					if (S.find(c[k]) == S.end()) {
						S.insert(c[k]);
						std::cout << c[k] << " ";
					}
				}
			}
			int x = pfactor[i].first * pfactor[(i + 1) % pfactor.size()].first;
			if (pfactor.size() == 2) {
				if (x != n && i != 1) std::cout << x << " ";
			} else if (x != n) std::cout << x << " ";
		}
		println;
		if (pfactor.size() == 2 && pfactor[0].second == 1 && pfactor[1].second == 1) {
			print(1);
		} else print(0);
	}
	return 0;
}