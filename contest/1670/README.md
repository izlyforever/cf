# [Codeforces Round #788 (Div. 2)](https://codeforces.com/contest/1670)

## A

负数在前，正数在后，然后看书否有序

## B

每个位置距离右边最近的 special number 的差距的最大值

## C

根据 $a, b$ 建图，看有多少个 size 大于 1， 且不包含原有元素的联通分支的个数

## D

找规律发现，每一步新增的个数一次是 $0, 2, 4, 4, 6, 8, 8, 10, 12, \cdots$

## E

## F

可以先求 $a_1 + \cdots, + a_n \geq l$, 且 $a_1 \oplus a_n = z$ 的个数，然后两个相减

我们不妨假设 $a_i < 2^{60}$


记 $f(x, z, i)$ 为 $a_1 + \cdots, + a_n \geq x$ 且 $a_1 \oplus a_n = z$，且 $a_j < 2^i$ 的答案

- 如果 $z \geq x$, $f(x, z, i) = (2^{n - 1})^i$
- 如果 $x > 2^{i} * n$，$f(x, z, i) = 0$
- 其他情况我们枚举即可，注意到如果 $x \leq 0$，$f(x, z, i) = (2^{n - 1})^i$ 为 “常量”，所以我们可以预处理组合数间隔后缀和，另外我们可以预处理所有的 $(2^{n - 1})^i$

然后喜提 TLE，意料之中...

看了 [jiangly 的代码](https://codeforces.com/contest/1670/submission/156114318) 后，才知道如何快速的做

假设 $dp[i][j]$ 表示前 $i + 1$ 个处理完了，然后总和剩余 $j$ 个 $2^i$ 的答案数，然后注意到最后的 $n$ 比较特殊，它表示剩余大于等于 $n$ 个 $2^i$ 的个数
