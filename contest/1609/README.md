# [Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)](https://codeforces.com/contest/1609)

## A

显然把每个数变成奇数后最大的作为基，所有 2 的幂次丢给它必然是最大的

## B

我以为是 subsequence 哎，想了快一个小时都没想明白（结果 E 题还真是 subsequence），各种想法，线段树都来了，发现不行。我服了。

> subsequence VS subarray(A subarray or substring will always be contiguous, but a subsequence need not be contiguous.)

但是这个题可以做成动态 01 问题，即从 "abc"，改成 “01”, subarray 变成 subsequence。就变成了经典线段数问题（求最小值，区间加更新）

## C

就直接素数筛预处理，然后分组暴力统计素数左右两边 1 的个数分别为 $n_l, n_r$ 然后贡献为 $(n_l + 1) \cdot (n_r + 1) - 1$，然后注意这一次的 $n_r$ 是下一次的 $n_l$（除非中间遇到了合数，此时 $n_l$ 清零）

