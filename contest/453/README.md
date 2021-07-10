## [Codeforces Round #259 (Div. 1)](https://codeforces.com/contest/453/)

### B：状态压缩 DP

给定数列 $a$，求满足元素两两互素的数列 $b$ 使得 $\sum |a_i - b_i|$ 最小

> 注意到 $b_i < 2 a_i$，因为否则取 $b_i = 1$ 即可。

由于 $60$ 内的素数个数为 17, 因此可以状态压缩 DP。设 `dp[i][j]` 表示使得 $\sum_{k = 1} ^ i |a_k - b_k|$ 最小，且$b_1 \cdots b_i$ 中所有出现的素因子的状态为 $j$。因此状态转移就是 `dp[i][j | factor[k]] = min(dp[i - 1][j] + |a_i - k|)`，其中 `factor[k]` 与 $j$ 没有交集。