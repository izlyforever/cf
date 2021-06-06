## [Codeforces Round #683 (Div. 2, by Meet IT)](https://codeforces.com/contest/1447)

### B：简单细节题

- 很早就知道，任意两个可以换，要考虑非正数的个数是否为奇数。
- 然后为奇数时，绝对值总和减去 2 倍的最大的非正数（！！！这是错了）。
- 后来想了半天终于知道时减去绝对值最小的数。
- 然后再之前的内容上改，写出了下面屎一样的 RE 代码！还 PE 了，最后 RE，吐了！

__此代码为 RE 代码！__

``` C++
#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
using pii = std::pair<int, int>;
using pll = std::pair<LL, LL>;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, m;
		std::cin >> n >> m;
		n *= m;
		std::vector<int> a, b;
		int r = 0;
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			r += abs(x);
			if (x <= 0) a.emplace_back(-x);
			else b.emplace_back(x);
		}
		if (a.size() & 1) {
			r -= std::min(*std::min_element(a.begin(), a.end()), *std::min_element(b.begin(), b.end())) * 2;
		}
		std::cout << r << std::endl;
	}
	return 0;
}
```

### C：经典问题：假 0-1 背包，真贪心

题意：给定 $n$ 件物品 $w_i$，给出一个 $k$ 件物品和在 $[\lfloor \frac{W}{2} \rfloor, W]$ 之间的一种方案

做法：对物品从大到小排序，然后贪心即可。

### D：DP

> 就是一个简单的 DP，写完我都有点虚...

### E：思维题

- 考虑最高位，如果最高位为 1，最高位为 0 的个数都大于 1，那么它们必然不连通，所以我们要将其中的一个变得不超过 1，注意不能贪心。并且注意到如果元素个数不超过 2，必然连通。
