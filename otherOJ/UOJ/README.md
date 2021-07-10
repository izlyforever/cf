## [清华集训 2016 组合数问题](https://uoj.ac/problem/275)

给定 $1 \leq n, m \leq 10^{18}$ 和素数 $p$，求所有 $0 \leq i \leq n, 0 \leq j \leq \min(i,m)$ 中有多少对 $(i, j)$ 满足 ${i \choose j}$ 是 $p$ 的倍数。

> ${i \choose j}$ 是 $p$ 的倍数当且仅当 $i, j$ 的 $p$ 进制中至少有一位 $x$ 满足 $i_x < j_x$（利用 Lucas 定理显然）。

所以最终答案就是 
$$
\frac{(n + 1)(n + 2)}{2} - \frac{k(k+1)}{2} - f(n, m)
$$
其中 $k = \max(0, n - m)$，$f(n, m)$ 表示 $i$ 的 每一位都满足 $i_x \geq j_x$ 的方案数，注意到此时必有 $i > j$，所以这里的 $i, j$ 限制分别是 $0 \leq i \leq n, 0 \leq j \leq m$. 并且可以让 $m = \min(m, n)$，我们可以从最低位开始 DP 就好了。

## [清华集训 2016 求和](https://uoj.ac/problem/269)

$f$ 是一个次数不超过 $m$ 的多项式，满足 $f(i) = a_i, i = 0, \cdots, m$，求
$$
\sum_{k = 0}^n f(k) {n \choose k} x^k (1 - x)^{n-k} \mod 998244353
$$

给定 $n, m, x$ 和 $a_0, \cdots, a_m$，其中 $1 \leq n \leq 10^9, 1 \leq m  \leq 2 \cdot 10^4, 0 \leq a_i, x \leq 998244353$

> 做法：利用二项式反演，记 $f(k) = \sum_{i = 0}^k {k \choose i} f_i$，则 $f_k = \sum_{i = 0}^k {k \choose i} (-1)^{k-i} f(i)$ 注意到 $f(x)$ 是次数不超过 $m$ 的多项式，所以 $f_{m + 1} = f_{m + 2} = \cdots = 0$

$$
\begin{aligned}
\sum_{k = 0}^n f(k) {n \choose k} x^k (1 - x)^{n-k} 
&= \sum_{k = 0}^n \sum_{i = 0}^k {n \choose k} {k \choose i} f_i x^k (1 - x)^{n-k} \\
&= \sum_{i = 0}^n \sum_{k = i}^n {n \choose i}  {n - i \choose k - i} f_i x^k (1 - x)^{n-k} \\
&= \sum_{i = 0}^n f_i {n \choose i}  x^i (1 - x)^ {n - i} \sum_{k - i = 0}^{n - i} {n - i \choose k - i} x^{k - i} (1 - x)^{i - k} \\
&= \sum_{i = 0}^n f_i {n \choose i}  x^i (1 - x)^ {n - i} (1 + \frac{x}{1-x})^{n - i} \\
&= \sum_{i = 0}^n f_i {n \choose i}  x^i
\end{aligned}\
$$
上述式子最后一项，只有 $m + 1$ 项，$f_0, \cdots, f_m$ 可以由 NTT 计算。
