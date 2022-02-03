# [Educational Codeforces Round 122 (Rated for Div. 2)](https://codeforces.com/contest/1633)

这一场很多小 trick，还是很有意思的，发挥的也比较正常，如果时间充裕，E 还是能做的

## A

设 $a = n \mod 7$，$b = n \mod 10$，
- 如果 $b >= a$，那么显然 $n - a$ 是 $7$ 的倍数，且最多只改变了一个位置
- 否则 $n + 7 - a$ 是 $7$ 的倍数，且 $b + 7 - a <= 7$, 即最多只改变了一个位置

## B

记 $0$ 的个数为 $x$
- 如果 $x = n - x$，那么答案就是 $x - 1$（随便去掉一个即可）
- 否则答案就是 $\min(x, n - x)$

## C

假设 $hc, dc, hm, dm$ 给定，那么 $c$ 能赢当且仅当 $\lceil \frac{hc}{dm} \rceil \cdot dc \gep hm$

## D

首先 dp 预处理，$dp[i]$ 表示从 $1$ 到 $i$ 所需的最小步数，然后问题就转化成  0-1 背包问题了

## E

这题表面上要计算 $10^8$ 次查询，但是其实，注意到边数 $m \leq 300$，而对于任意两条边 $a$ 比 $b$ 优当且仅当对于查询 $x$，$|x - a| < |x - b|$，所以如果 $x = \frac{a + b}{2}$，我们需要判断 $x - 1, x$，否则我们只需判断 $x$，所以整体复杂度为 $O(k) + m^3 \log m$
