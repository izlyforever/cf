# [Codeforces Round #738 (Div. 2)](https://codeforces.com/contest/1559)

## A

全体 and 一下

> 一开始没看到可以操作任意次，还直接暴力做

## B

直接贪心即可

## C

首先把 $1 \to n$ 连接起来，然后把 $n + 1$ 放在下面，首补 0，尾补 1。如果有连续的 `01` 出现，那么就有路

## E

题解写的好呀，先不考虑 gcd，然后可以 $O(n m)$ 的 考虑和以及答案 dp 的做即设 $f(l_i, r_i, m)$ 为满足 $a_i \in [l_i, r_i]$，且 $\sum_{i = 1}^n a_i \leq m$ 的数组 $(a_1, \cdots, a_n)$ 个数。

> 这里可以先平移，然后通过类和的方式得到答案

那么答案就是

$$
\sum_{a_1 = l_1}^{r_1} \cdots \sum_{a_n = l_n}^{r_n} [\gcd(a_1, \cdots, a_n) == 1] g(a_1, \cdots, a_n)
$$

若 $(a_1, \cdots, a_n)$ 满足条件则 $g(a_1, \cdots, a_n) = 1$，否则为 0

化简之后，答案为

$$
\sum_{d=1}^M\mu(d)\sum_{a_1=\lceil\frac{l_1}{d}\rceil}^{\lfloor\frac{r_1}{d}\rfloor}\sum_{a_2=\lceil\frac{l_2}{d}\rceil}^{\lfloor\frac{r_2}{d}\rfloor}\cdots\sum_{a_n=\lceil\frac{l_n}{d}\rceil}^{\lfloor\frac{r_n}{d}\rfloor}g(a_1d,a_2d,\ldots,a_nd)
$$

所以就可以在 $O(n M \log M)$ 解决了


> 若此题的所有 $l_i, r_i$ 都一致，那么此题就可以用 FFT 在 $O(m \log^2 m \log n)$
