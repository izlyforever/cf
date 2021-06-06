## [Codeforces Round #654 (Div. 2)](https://codeforces.com/contest/1371)

### E：给定长为 $n$ 的数组和素数 $p$，记满足 $x+i < a_{\sigma(i)},0\leq i<n$ 的排列个数为 $f(x)$，输出所有 $x$ 使得 $p \not | n$

> 先排序，并且注意到 $x \in (\max a_i-n,\max a_i+n)$ 之间。

记 $b_i$ 为数组中小于等于 $i$ 的元素个数。则 $f(x) = \prod\limits_{i=x}^{x+n-1} b_i-(i-x) = \prod \limits_{i=x}^{x+n-1} x-(i-b_i)$，所以我们预处理出 $i-b_i$ 即可。