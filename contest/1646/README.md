# [Codeforces Round #774 (Div. 2)](https://codeforces.com/contest/1646)

## A

注意到 $0 \leq a_i < n$ 类型的数加起来小于 $n^2$

## B

先排序，然后 红色选最小的 $k + 1$ 个，蓝色选最大的 $k$ 个，看是否可行，当然了前提是 $2 \cdot k < n$

## C

注意到阶乘是相当大的，因此 $$[6, 10^12]$ 中的阶乘数仅有 $12$ 个，然后可枚举出 $2^12$ 中可能，然后剩下的值就用二进制表示即可

## D

注意到如果这个节点为 good，它的值必然是它的 degree，否则它的值为 1（注意到部分节点同事满足这两个条件）。然后我们就对子树 dp 搞一下即可，当然了如果父亲节点为 good，子节点必然值必为 1，否则子节点任意。

搞完之后回溯即可

## E

啥时候 $i^x = j^y$ 呢，分解素因子，那么我们发现

$(p_1^{a_1} \cdots p_n^{a_n})^x = (p_1^{b_1} \cdot p_n^{b_1})^y$

当且仅当 $(a_1, \cdot, a_n)$ 于 $(b_1, \cdots, b_n)$ 成比例。

因此可以认为 $\gcd(a_1, \cdots, a_n) = 1$ 是“占优的”

所以我们先剔除掉形如 $x^2, x^3, \cdots, x^k$，其中 $k \leq \log_2 n$

然后依次对每一个没有剔除的 $i$，仅有 $i^2, i^3, \cdots, i^k$，可能满足 $i^x = j^y$，相当于看

$$
1, 2, \cdots, m \\
2, 4, \cdots, 2m \\
\vdots \\
k, 2k, \cdots, km \\
$$

（用 `map` 会 TLE）中有多少个不同的数（注意到这个值仅与 $k$ 有关，所以可以提前计算保存下这 $k$ 个值）

注意到 $km = O(m \log n)$，所以可以开数组保存下来，所以就可以不用搞 `map` 了，甚至连 `if` 都不需要
