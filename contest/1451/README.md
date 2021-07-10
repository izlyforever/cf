## [Codeforces Round #685 (Div. 2)](https://codeforces.com/contest/1451)

### C

题意：给定长为 n 的由小写字母组成的字符串 `a, b`，可以将 `a` 相邻的位置互换（因此所有位置都可以互换），也可以将长为 $k$ 且每一位都相同的字母全部变成下一个字母。

做法：一开始想排序之和贪心（[这份代码](https://codeforces.com/contest/1451/submission/99143008)），后来发现 `n = 3, k = 2` 时 `aab` 变成 `zzy` 就会出问题。我还以为思路没问题，又交了一遍，属实天真。

> 此题考虑每个数的个数会更简单！怪不得他们做的这么快...

### D：很好博弈问题

题意：从 (0, 0) 开始，每次可以向上或向右走 k 个单位（但是和起点距离不能超过 d），两人轮流走，谁不能走了谁输。

显然可以简化成走一个单位，距离不超过 $\frac{d}{k}$. 没过一小会，我就想到了，若 $2 x^2 \leq \frac{d^2}{k^2} < 2 (x + 1)^2$，那么，如果 $x^2 + (x + 1)^2 \leq \frac{d^2}{k^2}$，那么先手赢，否则先手输。

> 注意到 $x^2 + (x + 2)^2 = 2 (x + 1)^2 + 2 > d$


### E：交互题

题意：给定 n（为 2 的幂次，且大于 2），猜测一个长为 n ，取值在 `[0, n - 1]` 的数列。每次可以询问，`XOR i j`，`OR i j`，`AND i j` 中的一种（$i \neq j$）。询问次数不超过 n + 1。

> 上面 `OR` 和 `And` 用一个即可，我们这里用 `And`，`OR` 也类似。 

做法：所有的数和第一个数异或（自己跟自己异或为 0，省一次查询），如果有相同的结果，那么做一个 AND 就知道第一个数为多少了，否则所有值都出现了，那么我们可以找到一个 i 使得 $r[1] \wedge r[i] = 2^n - 1$，此时 $r[1] \And r[i] = 0$，我们再找一个数 j，求 `r[i] & r[j]` 以及 `r[1] & r[j]` 再利用 `a + b = a ^ b + 2 (a & b)` 就可以求出 `r[1]` 了。

> 其实本题另一种处理技巧，不需要 $n$ 为 2 的幂次，只需考虑异或为 1 和 2 的 `i,j`。下面做法基于此想法


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
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 1; i < n; ++i) {
		std::cout << "XOR 1 " << i + 1 << std::endl;
		std::cin >> a[i];
	}
	int x = -1;
	std::vector<int> b(n, -1);
	for (int i = 0; i < n; ++i) {
		if (b[a[i]] == -1) b[a[i]] = i;
		else {
			std::cout << "AND " << b[a[i]] + 1 << " " << i + 1 << std::endl;
			int tmp;
			std::cin >> tmp;
			x = tmp ^ a[i];
			break;
		}
	}
	if (x == -1) {
		int t1, t2;
		std::cout << "AND " << 1 << " " << b[1] + 1 << std::endl;
		std::cin >> t1;
		std::cout << "AND " << 1 << " " << b[2] + 1 << std::endl;
		std::cin >> t2;
		x = t1 | (t2 & 1);
	}
	std::cout << "! " << x;
	for (int i = 1; i < n; ++i) std::cout << " " << (x ^ a[i]);
	std::cout << std::endl;
	return 0;
}
```