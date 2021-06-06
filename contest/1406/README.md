## [Codeforces Round #670 (Div. 2)](https://codeforces.com/contest/1406/)


### D：经典数学题

给定数列 $a$, 求单调递增数列 $b$ 和单调递减数列 $c$，使得 $a_i = b_i + c_i$，并且使得 $b, c$ 中的最大值最小（即 $\max(b_n, c_1)$ 最小。

如果 $a_i < a_{i+1}$ 令 $b_{i +1} = b_i + a_{i + 1} - a_i$，否则 $c_{i + 1} = c_i + a_{i + 1} - a_i$。
设 $c_1 = x$，$b_ 1 = a - x$，容易看出 $b_n = \sum_{i = 2}^n \max{0, a_{i} - a_{i-1}}$。并且每次更新只和 $l, r$ 节点有关。
