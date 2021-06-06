## [Codeforces Round #585 (Div. 2)](https://codeforces.com/contest/1215/)


### E：给定长度为 $n$ 数据范围 $[1,20]$ 的数组，求最少交换相邻位置元素使得相同的数字都紧挨着

> 参考 [cf1215e](https://skywt.cn/posts/cf1215e)，注意到交换两个数字，其它数字的相对位置不发生改变

__状态 dp__：设 `dp[mask]` 表示状态为 `mask` 的最小交换次数，其中 `mask&(1<<i)=1` 表示值为 `1+i` 的数已经被考虑到了。所以 $dp[2^{20}-1]$ 就是我们要的结果。状态转移
$$
dp[mask] = \min_{j \in mask} dp[mask\wedge2^{j}] + \sum_{k \in mask\wedge2^{j}} cnt(j,k)
$$
其中 `cnt(j,k)` 表示把	所有的 `j` 移动到 `k` 前面需要的次数。

> 代码基本 copy [WZYYN](https://codeforces.com/profile/WZYYN) 的[代码](https://codeforces.com/contest/1215/submission/60614830)
