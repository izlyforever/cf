
### [Codeforces Round #722 (Div. 1)](https://codeforces.com/contest/1528)

> 好高骛远导致又一次离 master 最近的一次

又是一次 dfs 序的应用！！！

#### A：绝对值最值问题

注意到最大值必然在边界取到，所以树上 DP 即可

#### B：找规律 DP

不难发现 $a_n = \sum_{i = 1}^{n - 1} a_i + d(n)$，所以整体复杂度 $O(n \log n)$

#### C：dp 序应用

这题我知道要用 dfs 序，我也知道 dfs 序的性质：$u$ 是 $v$ 的祖先，当且仅当 $in[u] \leq in[v] \leq out[v] \leq out[u]$，但是我们需要的是反过来，这样就很多了，所以我因为我做不了，然后就取读其它题，然后专注最后一题，未果。其实 dfs 还有一个基本的性质，不存在交叉的情况，即不存在 $u, v$ 满足 $in[u] \leq in[v], out[u] \leq out[v]$，所以如果它们不互为祖先关系，那么必然是两两不交的！


#### F：经典组合问题（Stirling 数和下降幂的应用）

题解一波对应操作，就把问题转化成求

$$
\begin{aligned}
\sum_{i = 0}^n \binom{n}{i} n^{n - i} i^k 
&= \sum_{i = 0}^n \binom{n}{i} n^{n - i} \sum_{j = 0}^i S(k, j) j! \binom{i}{j} \\
&= \sum_{j = 1}^n S(k, j) j! \binom{n}{j} \sum_{i = j}^{n} \binom{n - j}{i - j} n^{n - i} \\
&= \sum_{j = 1}^n S(k, j) j! \binom{n}{j} (n + 1)^{n - j}
\end{aligned}
$$

> 注意到上述式子中 $j > k$ 时 $S(k, j) = 0$
