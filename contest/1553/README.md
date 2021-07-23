# [Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)](https://codeforces.com/contest/1553)

## A

显然 interesting 当且仅当尾数为 9

## B

反正成立当且仅当 t 可以写成 BCBD 且 DBC 是 s 的子列，或者 ABCB 且 ABC 是 s 的子列

## C

一开始以为顺序可变，搞了半天，浪费时间，只需要奇数 `?` 和偶数 `?` 分别取 $0, 1$ 和 $1, 0$ 即可

## D

注意到可以从后往前看，此时再注意到一次删除，本质上去掉了两个字符即可

## E

注意到 `cyclic shifts` 可以表达为 $p_i = (i - k) \mod n$，然后官方题解说到满足初始条件的 $k$ 必然要满足和 $a_i = p_i$ 的个数不小于 $n - 2 m$，而由于 $0 < m < \frac{n}{3}$，因此满足条件的不超过 3 个。然后平移之后看圈即可（因为要还原嘛）

## F

我也知道 $(x \mod y) = x - (x / y)y$, 但是哎。根据官方题解

$$
\begin{aligned}
s_k = \sum_{1 \le i, j \le k, i > j} (a_i \bmod a_j) \\
t_k = \sum_{1 \le i, j \le k, i < j} (a_i \bmod a_j)
\end{aligned}
$$

因此 

$$
s_k = s_{k - 1} + \sum_{i = 1}^{k - 1} (a_k - \lfloor \frac{a_k}{a_i} \rfloor a_i) = s_{k - 1} + a_k (k - 1) - \sum_{i = 1}^{k - 1} a_i \lfloor \frac{a_k}{a_i} \rfloor
$$

依然不好算，因此我们对每个 $i$，看它对 $s_k$ 的贡献

若 $a_k \in [d a_i, (d + 1) a_i)$, 则它的贡献就是 $-d a_i$

因此我们只需要在每个 $a_i$ 倍数上的点加值即可

我们再考虑 $t_k$:

$$
t_k = t_{k-1} + \sum_{i=1}^{k-1}a_i - \sum_{i=1}^{k-1} (a_k \cdot \lfloor \frac{a_i}{a_k} \rfloor)
$$

同理，$a_k \in [d a_i, (d + 1) a_i)$ 则贡献为 $d a_i$

> 两个树状数组搞定