## [Codeforces Raif Round 1 (Div. 1 + Div. 2)](https://codeforces.com/contest/1428)

### D：模拟题

> 由简单到复杂一步步的来，很不错的题。

### E：经典问题，正整数划分最值问题（可看作优先队列模板题）

> 若此题 $k$ 特别大，可二分 cmpVal 的题来解决

## F: 经典 DP

题意：给定 0-1 序列 S，设 $f(l, r)$ 表示 $S_l S_{l + 1} \cdots, S_{r}$ 中最长连续 1 的个数，求 $\sum_{l = 1}^n \sum_{r = l}^n f(l, r)$

> [官方题解](https://codeforces.com/blog/entry/83771) 实在是太精彩了！这种直方图的做法真的很 Nice！