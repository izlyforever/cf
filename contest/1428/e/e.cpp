#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
using pii = std::pair<int, int>;
 
LL val(const int &x, const int &n) {
	int xn = x / n, rn = x - xn * n;
	return 1ll * xn * xn * (n - rn) + 1ll * (xn + 1) * (xn + 1) * rn;
}
LL cmpVal(const pii &A) {
	return val(A.first, A.second) - val(A.first, A.second + 1);
}
class cmp {
public:
	bool operator() (const pii &lhs, const pii &rhs) const {
		return cmpVal(lhs) < cmpVal(rhs); 
	}
};
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k;
	std::cin >> n >> k;
	std::priority_queue<pii, std::vector<pii>, cmp> Q;
	for (int i = 0, x; i < n; ++i) {
		std::cin >> x;
		Q.push({x, 1});
	}
	while (n < k) {
		++n;
		auto [x, cnt] = Q.top();
		Q.pop();
		Q.push({x, cnt + 1});
	}
	LL r = 0;
	while (!Q.empty()) {
		auto [x, cnt] = Q.top();
		Q.pop();
		r += val(x, cnt);
	}
	print(r);
	return 0;
}