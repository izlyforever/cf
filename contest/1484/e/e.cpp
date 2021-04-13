#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	// 设 a[i][j] 为从 j + 1 到 i 这一段放在一起的结果
	// f[i] = \max(f[j] + a[i][j])，注意到如果最后一段不以 i 为最低点，那么删除这个点不影响结果。
	int n;
	std::cin >> n;
	// 从 1 开头有其好处。
	std::vector<int> h(n + 1), b(n + 1);
	for (int i = 1; i <= n; ++i) std::cin >> h[i];
	for (int i = 1; i <= n; ++i) std::cin >> b[i];
	h[0] = INT_MIN; // 添加一个数，为了代码少一些判断。
	std::stack<int> S;
	S.push(0);
	std::vector<LL> mx(n + 1, INT64_MIN), f(n + 1);
	// mx[i] 表示以 i 为最低点，前方 f[j] 的最大值
	for (int i = 1; i <= n; ++i) {
		mx[i] = f[i - 1];
		while (h[S.top()] > h[i]) {
			mx[i] = std::max(mx[i], mx[S.top()]);
			S.pop();
		}
		f[i] = std::max(mx[i] + b[i], S.top() == 0 ? INT64_MIN : f[S.top()]);
		S.push(i);
	}
	std::cout << f[n] << '\n';
	return 0;
}