
### [1499](https://codeforces.com/contest/1499)

#### B：删除不连续的点之后是有序的

我也没有想到我会被这题卡，真的难受。我以为只要删除了前置 0 和后置 1 之后，没有连续的 0 或 1 即可了。但是忽略了 `100110` 这种 case。WA 的心态爆炸，WA 的代码：

``` C++
#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
	std::string s;
	std::cin >> s;
	int n = s.size(), i = 0;
	while (n > 0 && s[n - 1] == '1') --n;
	while (i < n && s[i] == '0') ++i;
	if (i == n) return 1;
	int cnt[2] {};
	for (int j = i + 1; j < n; ++j) if (s[j] == s[j - 1]) {
		++cnt[s[j] - '0'];
	}
	return cnt[0] == 0 || cnt[1] == 0;
}

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		std::cout << (solve() ? "YES\n" : "NO\n");
	}
	return 0;
}
```


#### C：经典问题

一开始就知道 奇偶要分开考虑，WA 到吐了。

#### D: gcd 类问题，还是好做的

#### E：动态规划

设 `dp[i][j][0/1]` 为 x 以 i 结尾， y 以 j 结尾，最终它们是否以 x 结尾的总答案数。有了这个状态，状态转移就明显了。
代码请参考 [dlalswp25 的代码](https://codeforces.com/contest/1499/submission/110348041)