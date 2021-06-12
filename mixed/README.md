## 牛客

### [牛客练习赛84](https://ac.nowcoder.com/acm/contest/11174)：质量很好的一场

> 好气啊，比赛结束过了 6 分钟才把 D 调试出来

一开始 D 题理解错了题意，以为当前如果有的话，不仅优先级最高，而且时间也会跟着更新，可惜并没有。

#### A：直接 map 即可

#### B：把 $4 \times 4$ 对应到一个非负整数 然后 BFS

#### C：4 阶容斥

即前两个遍历，后面两个就是简单的两个人的容斥。

> 即使是真三阶容斥，当时写的时候还是算错，是因为没有乘以系数：[可参考](https://ac.nowcoder.com/acm/contest/view-submission?submissionId=47969478)

#### D：好题

理解错了题意：

如果时间也跟着更新，那么做法应该是：[这里](https://ac.nowcoder.com/acm/contest/view-submission?submissionId=47969181)

但是由于不更新时间，但是优先度又是跟着真实时间走的。我们这样搞：

首先用队列 Q 记录以下在不考虑容量下，当前被缓存下来的 a 的下标，用 mp 和 cnt 这个表示互逆操作。即 $cnt[id] = timer, mp[timer] = id$，相当于 mp 存了优先度，而如果 mp 的容量大于 $m$，那么就要删除节点，而这也要被记录下面，比如说用 `S[id]` 记录节点 id 被删除的次数。好了，现在队列 Q 中的时间是单调的，如果 Q 中有东西过期了，我们自然要删除的，但是有可能这个点在之前因为容量的原因已经被删除了，此时就不用真的再删除一次，而是把 `s[id]` 减 1。


#### D：又是树上化成链上问题


#### F：Fibonacci 数列的最大公约数

利用 $F_{n + m} = F_{n - 1}F_{m} + F_n F_{m + 1}$，我们不难得到 $\gcd(F_{n}, F_{m}) = F_{\gcd(n, m)}$。所以原式可以转化成

$$
\sum_{d = 1}^n F_d \sum_{i_1 = 1}^{\lfloor \frac{n}{d} \rfloor} \cdots \sum_{i_k = 1}^{\lfloor \frac{n}{d} \rfloor} [gcd(i_1, \cdots, i_k) == 1]
$$

注意到，由于 $k$ 为常数，我们记

$$
g(n) = 
\sum_{i_1 = 1}^n \cdots \sum_{i_k = 1}^n [gcd(i_1, \cdots, i_k) == 1] = \sum_{d = 1}^n \mu(d) \lfloor \frac{n}{d} \rfloor^k
$$

所以最终答案为：$\sum_{d = 1}^n F_d g(\lfloor \frac{n}{d} \rfloor) = \sum (F \star \mu)(d) \lfloor \frac{n}{d} \rfloor^k$

注意到，我们记 $h(d) = \sum_{i = 1}^d (F \star \mu)(i)$，则 $h(\lfloor \frac{n}{d} \rfloor) = \sum_{d = 1}^n F(d) = F_{n + 2} - 1$

> 最优复杂度为 O(n^{\frac{3}{4}})$

$$
\sqrt{\frac{n}{1}} + \sqrt{\frac{n}{2}} + \sqrt{\frac{n}{\sqrt{n}}} + O(\sqrt{n}) = O(\sqrt{n} \int_0^{\sqrt{n}} x^{-\frac{1}{2}} dx) = O(n^{\frac{3}{4}})
$$

其实按照上面的这个思路，假设用 `unordered_map` 每次均摊 $O(1)$，那么预处理 $O(n^{\frac{2}{3}})$，我们有

$$
\sqrt{\frac{n}{1}} + \sqrt{\frac{n}{2}} + \sqrt{\frac{n}{n^{\frac{1}{3}}}} + O(n^{\frac{2}{3}}) = O(\sqrt{n} \int_0^{n^{\frac{1}{3}}} x^{-\frac{1}{2}} dx) = O(n^{\frac{2}{3}})
$$


### [武汉理工 2021 同步赛 F](https://ac.nowcoder.com/acm/contest/16786/F)

[官方题解](https://blog.nowcoder.net/n/7574bf87891a481b81082878149f6006) 和[我的提交](https://ac.nowcoder.com/acm/contest/view-submission?submissionId=47912933)

> 我一开始一直 TLE 原来是因为思路有问题，注意代码中求 sumPhi 会有很多公共项

> 注意到 $x = \min(\lfloor \frac{n}{i} \rfloor, \lfloor \frac{m}{j} \rfloor), gcd(i, j) = 1$ 等价于 $\gcd(xi, xj) = x$ 的最大的 $x$

这么说来这也是给出了更快做法（前提 $f(0) = 0$）

$$
\sum_{i = 1}^n \sum_{j = 1, gcd(i, j) = 1}^m f \left( \min(\lfloor \frac{n}{i} \rfloor, \lfloor \frac{m}{j} \rfloor) \right) = \sum_{i = 1}^n \sum_{j = 1}^m f(\gcd(i, j)) - f(\gcd(i, j) - 1)
$$


### [牛客 11189C](https://ac.nowcoder.com/acm/contest/11189/C)：贪心 + 并查集

我一开始搞成树上问题 TLE。有点可惜。并查集常数确实小很多。








## vjudge

### [凸优化借助凸包解决](https://vjudge.net/problem/Kattis-mobilization)

> 详细解释放在 [izlyforever](https://izlyforever.com/spookywooky/)

### [ZOJ 3820](https://vjudge.net/problem/ZOJ-3820)：树的重心 + 直径

题意：在一棵树上选择两个点，使得任意点到这两点的最小值的最大值最小。
> 如果仅仅选择一个点，那么这个问题就是树的重心。
> 
> 对此情况，将直径按照中点切开，然后分别求两颗子树的中心, [参考资料](https://blog.csdn.net/ok_again/article/details/40043197)

证明：如果 u,v 是满足条件的两个点，那么把他们沿着中间切开必然最优，然后反证它们在树的直径上。






## HDU

### [hdu 4747](http://acm.hdu.edu.cn/showproblem.php?pid=4747): MEX

求 $\sum_{1 \leq L \leq R \leq n} MEX(L, R)$)，其中 $MEX(L, R)$ 为使得 $a_L, a_{L + 1} \cdots, a_{R}$ 中没出现的最小自然数

> 同理与上面做法，代码不写了，懒得写线段树。

> 有的 MEX 定义包含 0, 有的不包含，无所谓啦。

## [HDU 6838 Battle for Wosneth](http://acm.hdu.edu.cn/showproblem.php?pid=6838)
> 有两个人记作 Alice 和 Bob，Alice 的生命值很高，所以可以认为是无限的，Bob 的生命值为 m。两个人的攻击命中率分别为 `p,q`。两个人轮流攻击对方。从 Alice 开始攻击，每次攻击的时候，如果 Alice 命中，那么能让对方的生命值减低 1，同时自己的生命值能恢复 1，如果 Bob 命中，那么能让对方的生命值减低 1，注意 Bob 不会自己回血。直到 Bob 的血量变为 0，游戏结束。Alice 想知道，游戏结束的时候，自己期望生命值。


不妨设，期望为 `a[m]`, 则显然 
`a[m] = p(1-q)(a[m-1]+1) + pq a[m-1] + (1-p)q(a[m]-1) + (1-p)(1-q)a[m]`
化简一下得到 $a_m =  a_{m - 1} + \frac{p - q}{p}$. 另外 $a_1 = p + (1 - p) q (a_1 - 1)  + (1 - p) (1 - q) a_1$，所以 $a_1 = \frac{p - q + pq}{p}$ 即 $a_m = \frac{p - q}{p} m + q$


## [HDU 6842 Battle for Wosneth2](http://acm.hdu.edu.cn/showproblem.php?pid=6842)
> 有两个人记作 Alice 和 Bob，生命值分别是 n,m，命中率分别为 p%,q%。两个人轮流攻击对方，从 Alice 开始攻击，每次攻击的时候，如果命中，那么能让对方的生命值减低 1，直到一方的生命值不超过 0 为止。问 Alice 胜的概率

设 `a[n][m], b[m][n]` 分别表示表示 Alice, Bob 胜的概率。则
`a[n][m] = p(1-b[n][m]) + (1-p)(1-b[n][m])`，
`b[n][m] = q(1-a[m-1][n] + (1-q)(1-a[m][n]`，
所以我们有`(p+q-pq) a[n][m] = p(1-q) a[m][n] + (1-p)q a[m-1][n] + pq a[m-1][n-1]`




## UOJ

### [清华集训 2016 组合数问题](https://uoj.ac/problem/275)

给定 $1 \leq n, m \leq 10^{18}$ 和素数 $p$，求所有 $0 \leq i \leq n, 0 \leq j \leq \min(i,m)$ 中有多少对 $(i, j)$ 满足 ${i \choose j}$ 是 $p$ 的倍数。

> ${i \choose j}$ 是 $p$ 的倍数当且仅当 $i, j$ 的 $p$ 进制中至少有一位 $x$ 满足 $i_x < j_x$（利用 Lucas 定理显然）。

所以最终答案就是 
$$
\frac{(n + 1)(n + 2)}{2} - \frac{k(k+1)}{2} - f(n, m)
$$
其中 $k = \max(0, n - m)$，$f(n, m)$ 表示 $i$ 的 每一位都满足 $i_x \geq j_x$ 的方案数，注意到此时必有 $i > j$，所以这里的 $i, j$ 限制分别是 $0 \leq i \leq n, 0 \leq j \leq m$. 并且可以让 $m = \min(m, n)$，我们可以从最低位开始 DP 就好了。

### [清华集训 2016 求和](https://uoj.ac/problem/269)

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



## [百度之星 2020 初赛 1008](http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=889&pid=1008)：数论函数题

已知，$f(n) = \displaystyle \sum_{d|n} d \cdot [\gcd(d,\frac{n}{d}) == 1]$，求 $\displaystyle \sum_{n=1} ^N f(n)$

首先 
$$
f(n) = \sum_{d|n} d \cdot [\gcd(d,\frac{n}{d}) == 1] = \sum_{d|n} d \cdot \sum_{l| \gcd(d,\frac{n}{d})} \mu(l) = \sum_{l^2 | n} \mu(l) \cdot l \cdot g(\frac{n}{l^2})
$$
其中 $g(n) = \displaystyle \sum_{d|n} d$，所以 
$$
\sum_{n=1} ^N f(n) = \sum_{n=1} ^N \sum_{l^2 | n} \mu(l) \cdot l \cdot g(\frac{n}{l^2}) = \sum_{l=1}^{\sqrt{N}} \mu(l) l \sum_{n=1} ^{\lfloor \frac{N}{l^2} \rfloor} g(n) = \sum_{l=1}^{\sqrt{N}} \mu(l) \cdot l \cdot h(\lfloor \frac{N}{l^2} \rfloor)
$$
其中 $h(n) = \sum_{i = 1} ^n g(i) = \sum_{d=1}^n d \lfloor \frac{n}{d} \rfloor$，求 $h(n)$ 有众所周知的 $O (\sqrt{n})$ 的算法，所以总时间复杂度为 $O(\sum \frac{\sqrt{N}}{l}) = O(\sqrt{N} \log N)$

另外一种计算思考：考虑每一个 $d$ 对答案的贡献，则 
$$
\begin{array}{lc}
ans_N &= \sum_{d=1} ^N d \sum_{x d \leq N}  [\gcd(x,d) == 1] \\
&=  \sum_{d=1} ^N d \sum_{x d \leq N}  \sum_{l|gcd(x,d)} \mu(l) \\
&= \sum_{l=1} ^{\sqrt{N}} \mu(l) l \sum_{d = 1} ^{\lfloor \frac{N}{l} \rfloor}  d \cdot \lfloor \frac{N}{l^2 d} \rfloor\\
&= \sum_{l=1} ^{\sqrt{N}} \mu(l) l \sum_{d = 1} ^{\lfloor \frac{N}{l^2} \rfloor} d \cdot \lfloor \frac{ \lfloor\frac{N}{l^2} \rfloor}{d} \rfloor \\
\end{array}
$$