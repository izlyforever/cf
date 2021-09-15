## [Codeforces Round #736 (Div. 2)](https://codeforces.com/contest/1549/)

### A 

注意到素数 $P \geq 5$，所以 $P$ 全为奇数，因此答案为 $2, p - 1$

### B

从左向右贪心即可，然后取了的位置标记为 -1

### C

注意到，$i$ 最终留下来 当且仅当 与 $i$ 相连的点编号都比它小，因此我们用 set 记录下每个点的连边情况，然后动态维护答案即可。

### D

注意到 $a_i \bmod m = a_{i+1} \bmod m = \ldots = a_j \bmod m$ 等价于

$m | (a_{i + 1} - a_i), \cdots, m | (a_j - a_{j - 1})$，因此我们可以先做差，然后找到最大的区间 $[i, j]$ 使得差值的 gcd 不为 1 即可。然后显然可以二分分治来做

> 根据这篇 [gcd](https://codeforces.com/blog/entry/63771)，我的复杂度为 $O(n \log n + n \log \max a_i)$

### E

显然答案是

$$
f(x) = \sum_{i = 1}^n \binom{3i}{x}
$$

类似于 $\binom{n + 1}{k + 1} = \binom{n}{k} + \binom{n}{k + 1}$，我们有

$$
\binom{n + 3}{k + 3} = \binom{n}{k} + 3 \binom{n}{k + 1} + 3 \binom{n}{k + 2} + \binom{n}{k + 3}
$$

> 怎么理解：$n + 3$ 个人选 $k + 3$ 个去旅游，其中有 3 个是你的好兄弟，然后根据你好兄弟去的个数分情况讨论

因此

$$
\begin{aligned}
f(x) &= \sum_{i = 1}^n \binom{3i + 3}{x + 3} - \binom{3i}{x + 3}  - 3 \binom{3i}{x + 1} - 3 \binom{3i}{x + 2} \\
 &= \binom{3n + 3}{x + 3} - 3 f(x + 1) - 3 f(x + 2)\end{aligned}
$$

考虑生成函数也是一个很不错的做法即

$$
P(k) = (1 + k)^3 + \cdots + (1 + k)^{3N} = \frac{(1+k)^{3N+3}-(1+k)^3}{(1+k)^3-1}
$$

求 $P(k)$ 的 $x$ 次系数

### F1

> F2 下次一定吧

首先必然用到 [Pick's theorem](https://baike.baidu.com/item/%E7%9A%AE%E5%85%8B%E5%AE%9A%E7%90%86/7554085)：面积 S 和内部格点数目 n、多边形边界上的格点数 m 的关系：

$$
S = n + \frac{s}{2} - 1
$$

注意到题目中桩子的坐标都是偶数，因此 $S$ 是偶数，要 $n$ 为奇数，仅需 $s$ 是 $4$ 的倍数

设 $(x_1, y_1), (x_2, y_2), (x_3, y_3)$ 为选中的点，那么

$$
s = \gcd(x_2 - x_1, y_2 - y_1) + \gcd(x_3 - x_1, y_3 - y_1) + \gcd(x_3 - x_2, y_3 - y_2)
$$

注意到我们仅关心 $s$ 是否是 $4$ 的倍数，注意到出现的数字都是 2 的倍数，因此我们可以同时除以 2，然后看 $s$ 是否是 2 的倍数即可

