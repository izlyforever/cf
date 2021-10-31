# [Educational Codeforces Round 116 (Rated for Div. 2)](https://codeforces.com/contest/1606)

## A

显然只需要首尾相同即可

## B

显然先倍增，然后当台数大于 k 时，开始每次加 k

## C

从低位到高位，直接贪心即可

## E

直接 dp，注意到 $dp[n][x] = x^n, n < x$, $dp[n][x] = dp[n][x - n - 1] + \binom{n}{1}dp[n - 1][x - n + 1] \cdot (n - 1) + \cdots, + \binom{n}{n} dp[0][x - n + 1] \cdot (n - 1)^n$

注意到 $dp[0][x] = 1, dp[1][x] = 0$
