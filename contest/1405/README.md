## [Codeforces Round #668 (Div. 2)](https://codeforces.com/contest/1405/)

### D：树的直径

$A, B$ 分别在树上某两点，每次移动的距离最大值为 $da, db$，$A$ 先移动。
如果 $A$ 有策略在有限步后与 $B$ 在同一点，那么就 $A$ 获胜，否则 $B$ 获胜。

$A$ 胜可以分这三种情况：
- $A$ 直接能到 $B$
- 两倍 $da$ 大于或等于 __树的直径__
- 两倍 $da$ 大于或等于 $db$

### E：高端树状数组

> [官方题解](https://codeforces.com/blog/entry/82366)
