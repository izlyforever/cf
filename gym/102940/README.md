## [UTPC Contest 01-22-21 Div. 1 (Advanced)](https://codeforces.com/gym/102940)

### H

长为 k 取值在 [1, n] 且满足 $a_i \mid a_{i + 1}$ 的序列有多少个。

我一开始以为跟 n 的素因子有关，后来发现没法直接推公式，然后发现是一个 dp 问题，令 `dp[k][x]` 表示长为 k 满足  $a_i \mid a_{i + 1}$ 且每项都是 x 的因子的序列个数。答案必然就是 $\sum_{x = 1}^n dp[k - 1][x]$。复杂度 $O(k n \log n)$
