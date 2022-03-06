## [Educational Codeforces Round 97 (Rated for Div. 2)](https://codeforces.com/contest/1437/)

### C：经典问题之动态规划

给定 $1 \leq a_i \leq n$，求两两不同的正整数 $b_i$，使得 $\sum_{i = 1}^n |a_i - b_i|$ 最小。
显然只要 $b$ 的值域确定了，答案就确定了，且 $1 \leq b_i < 2n$。所以就可以对 $a_i$ 排序，然后再 `1 ~ 2n - 1` 中选 $n$ 个数，使得结果最小。
