## [牛客练习赛85](https://ac.nowcoder.com/acm/contest/11175)

> 最近几场牛客质量都挺高，是牛客变强了还是我变菜了呀

### A：数字判断

看 degree 为 3 的节点有多少个即可

### B：前后凑一下即可

对每个位置 $i$，考虑 $i$ 后面只取一个的答案，然后取 $j ~ i$ 之后 $j$ 前面的答案


### C：ST 表

首先计算出每一个的下一个位置，然后就开始建立跳表


### D：线段树 + Bitset

先预处理一下素数和最小素因子即可


### E 和 F 也是好题，太繁琐的不搞了



## [牛客挑战赛51](https://ac.nowcoder.com/acm/contest/11191)

说实话，这场质量有点高

### A：真以为是签到题就炸了

首先有答案必然要保证 $\text{lcm}(a, c) | \gcd(b, d)$

### B：添加 x 条边使得连通数最大

一开始以为最小，要是求最小这题就没啥意思了

这个题肯定是贪心，先搞连通块中节点最多的，并查集搞一搞就行

### C：回文

> 这个可以做成模板

先求 `nth`，再求 `par`，像极了 $\pi(x)$ 和 $p_n$ 的操作

### E: gcd once more

根据官方题解利用 Euler 反演：$n = \sum_{d | n} \phi(d)$，我们有：

$$
\gcd(i, j) = \sum_{d | i, d | j} \phi(d)
$$

更一般地，我们有 Mobius 反演：$f(n) = \sum_{d | n} f'(d) \equiv \sum_{d | n} (f \star\mu)(d)$ 

$$
f_{\gcd(i, j)} = \sum_{d | i, d |j} f'(d)
$$

因此

$$
\sum_{i = 1}^n \sum_{j = 1}^n \sum_{k = 1}^n \gcd(i, j) \gcd(i, k) \gcd(j, k) = \sum_{d1 = 1}^n \sum_{d2 = 1}^n \sum_{d3 = 1}^n \frac{n}{[t1, t2]} \frac{n}{[t1, t3]} \frac{n}{[t2, t3]}
$$

其中 $[t_i, t_j]$ 为 $t_i, t_j$ 的最小公倍数，然后使用三元环计数即可解决

本想用 set 存来替代求 gcd，但是发现慢的离谱!!!。

我们先枚举 $\gcd(i, j) == 1, i j <= n$：$O(n \log^2 n)$ 得到所有的 $(i, j)$（总数为 $O(n \log n)$），再得到所有的 $O(n \log^2 n)$ 得到所有的 $\text{lcm}(i, j) <= n$（总数 $m = O(n \log^2 n)$，且记录下这个值要在后面用）。因此最终复杂度为 $O(m \sqrt{m}) = O(n \sqrt{n} \log^3 n)$，然而实际上 $n = 100000$ 时，环的个数仅有 `120064036`

> 更[一般地](https://loj.ac/p/2476) 同样的原理解决

## [牛客练习赛84](https://ac.nowcoder.com/acm/contest/11174)：质量很好的一场

> 好气啊，比赛结束过了 6 分钟才把 D 调试出来

一开始 D 题理解错了题意，以为当前如果有的话，不仅优先级最高，而且时间也会跟着更新，可惜并没有。

### A：直接 map 即可

### B：把 $4 \times 4$ 对应到一个非负整数 然后 BFS

### C：4 阶容斥

即前两个遍历，后面两个就是简单的两个人的容斥。

> 即使是真三阶容斥，当时写的时候还是算错，是因为没有乘以系数：[可参考](https://ac.nowcoder.com/acm/contest/view-submission?submissionId=47969478)

### D：好题

理解错了题意：

如果时间也跟着更新，那么做法应该是：[这里](https://ac.nowcoder.com/acm/contest/view-submission?submissionId=47969181)

但是由于不更新时间，但是优先度又是跟着真实时间走的。我们这样搞：

首先用队列 Q 记录以下在不考虑容量下，当前被缓存下来的 a 的下标，用 mp 和 cnt 这个表示互逆操作。即 $cnt[id] = timer, mp[timer] = id$，相当于 mp 存了优先度，而如果 mp 的容量大于 $m$，那么就要删除节点，而这也要被记录下面，比如说用 `S[id]` 记录节点 id 被删除的次数。好了，现在队列 Q 中的时间是单调的，如果 Q 中有东西过期了，我们自然要删除的，但是有可能这个点在之前因为容量的原因已经被删除了，此时就不用真的再删除一次，而是把 `s[id]` 减 1。


### D：又是树上化成链上问题


### F：Fibonacci 数列的最大公约数

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


## [武汉理工 2021 同步赛 F](https://ac.nowcoder.com/acm/contest/16786/F)

[官方题解](https://blog.nowcoder.net/n/7574bf87891a481b81082878149f6006) 和[我的提交](https://ac.nowcoder.com/acm/contest/view-submission?submissionId=47912933)

> 我一开始一直 TLE 原来是因为思路有问题，注意代码中求 sumPhi 会有很多公共项

> 注意到 $x = \min(\lfloor \frac{n}{i} \rfloor, \lfloor \frac{m}{j} \rfloor), gcd(i, j) = 1$ 等价于 $\gcd(xi, xj) = x$ 的最大的 $x$

这么说来这也是给出了更快做法（前提 $f(0) = 0$）

$$
\sum_{i = 1}^n \sum_{j = 1, gcd(i, j) = 1}^m f \left( \min(\lfloor \frac{n}{i} \rfloor, \lfloor \frac{m}{j} \rfloor) \right) = \sum_{i = 1}^n \sum_{j = 1}^m f(\gcd(i, j)) - f(\gcd(i, j) - 1)
$$


## [牛客 11189C](https://ac.nowcoder.com/acm/contest/11189/C)：贪心 + 并查集

我一开始搞成树上问题 TLE。有点可惜。并查集常数确实小很多。
