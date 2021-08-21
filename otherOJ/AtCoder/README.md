## [AtCoder Beginner Contest 215](https://atcoder.jp/contests/abc215)

### D

显然所有不包含 $A_i$ 们有的素因子即可

### E

状态 DP，x 的二进制表示当前有哪些数，然后再看标记一下尾巴是什么即可

### F

我们可以先排序，然后一个单调递减 dn，一个单调递增 up。每次新来一个，那么必然是可以二分搞定的。具体说就是如果当前点为 (x, y)，那么我们可以看 y 的值来判断是否加入其中一个，并且计算当前值的时候，可以二分找到纵坐标大于或者小于它的位置，然后再二分找到横坐标占优和纵坐标占优的位置即可


## [AtCoder Beginner Contest 214](https://atcoder.jp/contests/abc214)

### D

> 经典树上任意两点路径最大值

将边从小到大排序，那么贡献就是 $u, v$ 所在联通块的乘积乘以边权

### E

我们贪心来做。首先按照 pair 排序，当前可取为最小值，用一个 multiset 记录若 $[x, y]$ 中 $x \leq now$ 则将 $y$ 丢进 multiset 中，否则 $x > now$(后面的也必然这样) 我们可以泄洪了。

> 这样必然是不亏的。充分利用了左边的资源，multiset 中元素只关心 $y$ 这是因为他们的横坐标小于 now 因此是对等的。

一开始没想清楚就写，想清楚了之后，以前的小于写成大于号一直没发现，气完了

## [AtCoder Beginner Contest 212](https://atcoder.jp/contests/abc212)：经典

### A：签到

### B：签到

### C：排序 + 二分查找

### D：水涨船高

都提示了 Multiset 了，我还在那写 set 呢

### E：特别有意思的一题

我们设第 $i$ 步在 $j$ 处的方案数为 `a[i][j]`，那么状态转移显然，然而边太多因此不太行，但是注意到删了的边并不会太多，因此我们把总和减去删掉的边即可。注意：自己到自己的边必然是算删掉的边的

> 比赛结束 3 分钟做出来，前面浪了会，看最后一题，导致没时间做

### F

根据 bus 建跳表，然后再每组答案二分查找起点

### G

首先排除 $(0, 0)$ 这个答案，不妨设 $x, y$ 非零，然后用原根定理 $x = g^i, y = g^j$，即

$$
i k \equiv j \mod (p - 1)
$$

设 $n = p - 1$, 所以最终答案为

$$
1 + \sum_{i = 1}^n \frac{n}{\gcd(i, n)} = 1 + \sum_{d = 1}^n d \phi(d)
$$

然后我通过分解素因子的方式，可以做到 $O(\sqrt{n})$ 的复杂度

### H：超级经典

FWT 变换 + Nim


## [AtCoder Grand Contest 054](https://atcoder.jp/contests/agc054)

### A：答案只有三种

如果首尾不等，答案为 1，若有两个相邻的字母分别不等于首和尾，那么答案是 2，否则为 3

### B：用 map 做背包

统计和为 s 且个数为 i 的数列有多少个。然后答案就是

$$
\sum_{s = \frac{\sum a_i}{2}} fac[i] fac[n - i] mp[\{s, i\}]
$$


## [AtCoder Beginner Contest 207](https://atcoder.jp/contests/abc207)

### A: 求和减去最小值

### B：向下取整

### C：区间乘 2，左加右减

### D：平移旋转，使得最终为 1

只看距离和不同距离的叉积瞎搞过去了

> 实际应该考虑重心和任意一个不在重心上的点，然后确定变换


### E：DP 优化

首先设 `dp[i][j]` 为 将 $A_1, \cdots, A_i$ 分成 $j$ 段的答案数，则显然

$$
dp[i][j] = \sum_{k < i, s[i] - s[k] \equiv 0 \mod j } dp[k][j - 1]
$$

其中 $s[i] = \sum_{j = 1}^i A_i$

设 $b[i][j] = \sum_{k < i, s[k] \equiv i \mod j} dp[k][j - 1]$，则 $dp[i][j] = b[s[k] \mod j][j - 1]$


## [AtCoder Beginner Contest 205](https://atcoder.jp/contests/abc205)

提前 20 分钟 AK 了（且全部 1A），开心，最后一题本来想放弃了，但是在整理模板的时候。

### A：$a \cdot b / 100.0$

### B：看是否有点被访问过了

### C：看 $c$ 是否是 偶数

### D：看每个数前面有多少个数，然后二分查找即可

### E：类似 Catalan 数的操作

找 $(n, m)$ 关于直线 $y = x + k + 1$ 的对称点 $(n - k - 1, m + k + 1)$，再考虑一下 $n \geq k$ 和 $n > n + k$ 的特殊情况即可

### F：建立网络流

建立源点 $0$ 和 汇点 $sz = 1 + h + w + 2 \cdot n$。然后 $h$ 行用节点 $1, \cdot, h$ 标记，$w$ 列分别用 $h + 1, \cdots, h + w$ 表示，然后每一个框框用两个节点  $h + w + 2i - 1, h + w + 2i$ 表示。源点向行建立流量为 1 的边，列向汇点建立流量为 1 的边，根据框框容量建立，行向  $h + w + 2i - 1$ 连边， $h + w + 2i - 1$ 和 $h + w + 2i$ 连边， $h + w + 2i$ 和列连边即可。最后跑一下 Dinic 即可。


## [AtCoder Regular Contest 122](https://atcoder.jp/contests/arc122)

### A：理解错了题意被卡

所有不能有两个连续减号出现的表达式的和。我们直接 DP 即可，记录上一步是加号还是减号的答案数，并且要记录分别有多少种。

### B：直接列出式子

考虑：
$$
\frac{x}{2} + A_i - \min(A_i, x)
$$
然后通过平移就会发现 $x$ 取中位数答案是最小的

### C：

我知道肯定跟 Fibonacci 数列有关，但是具体不知道怎么搞

[官方题解](https://atcoder.jp/contests/arc122/editorial/2071) 的观察利用了线性递推数列的线性性质！

我们一直操作 3 4 就会得到这样的序列：$x, y + x, x + y + x, \cdots$（假设总长度为 $S$）注意到奇数位置是 $x$，而且注意到 $i$ 位置会让最终答案 $F_{S-i}$。所以如果 $S$ 长度为奇数，哪就先 3 后 4，否则先 4 后 3。


### D：没想到 C 不会做，这题却能很快的独立完成

> 如果没有 C 题卡我时间，这题为必能做掉

首先我们注意到，最高位有主导作用，如果最高位为 1 的个数有奇数个，那么不然是这一类和为最高位为 0 的某一个贡献了答案，我们记作 solve2，否则，只需分别看这两类分别求答案的最大值即可。而 solve2 又可以由 solve2 自身递归解决。


### E：注意到 N 很小

[官方题解](https://atcoder.jp/contests/arc122/editorial/2073) 精髓啊，一个数可以放在最后面当且仅当 $LCM_{j \neq i}(\gcd(A_i, A_j)) < A_i$



## [AtCoder Beginner Contest 204](https://atcoder.jp/contests/ABC204/tasks)

### C：求邻接图的闭包

忘了用 bitset 贡献了一次 TLE

### D：背包

### E：最短路 Dijkstra

注意到，无论如何我们能走多快走多快，然后大不了取某个节点等待。注意到最小值，只需考虑不取整的情况，即考虑 $c + t + \frac{d}{t + 1}$ 的最小值，求导可知 $t = \sqrt{d} - 1$ 时，取得最小值 $x$，然后注意要取整，然后要看这个能否取到

经过严格论证之后发现 $f(t) = t + \lfloor \frac{a}{t} \rfloor, t > 0$ 的最小值 $\min f = f(\lfloor \sqrt{a} \rfloor + 1) = f(\lceil \sqrt{a} \rceil)$

### F：

这题就很像 [2020-2021 Winter Petrozavodsk Camp, UPC contest L 题](https://codeforces.com/gym/103098/problem/L)，[Motsu_xe 的代码](https://atcoder.jp/contests/ABC204/submissions/23257095) 特别值得借鉴。

[官方题解](https://atcoder.jp/contests/ABC204/editorial/2026) 给了好几个做法：最终确定为 $O(8^H \log W)$ 的矩阵幂做法。。那么如果我们写成矩阵形式，就可以知道递推公式的长度不会超过 $2^H$。从而 Berlekamp-Massey 就可以发挥作用了。

也就是说，我们只要求到 $W = 2^{H + 1}$，然后用 Berlekamp-Massey 算法即可。

我们设 $dp[i][mask][mask2]$ 先贴最左边，从上往下贴。然后需要用 dfs 式的 dp！终于[解决了](https://atcoder.jp/contests/ABC204/submissions/23325995)，舒服！


## [AtCoder Beginner Contest 202](https://atcoder.jp/contests/abc202/tasks)

### A：签到题

筛子问题

### B：签到题

数字字符倒过来

### C: 水题

利用 map，注意到 C 数列本质可变成 B 数列。

### D：组合数序

$a$ 个 'a'，$b$ 个 'b'，注意到，如果第一个位置填 'a'，那么最多有 $\binom{a + b - 1}{b}$ 个数，如果 k 大于它，那么说明只能填 'b' 此时 k 要减去这个数。

### E：经典树上问题

这个问题我一开始一直想用倍增做，然后发现复杂度不对，但是想不到别的做法，于是我就开始倍增做，然后代码直接爆炸，最后 TLE。

> 再次发现 dfs 序的重要性！！！



## [AtCoder Regular Contest 119](https://atcoder.jp/contests/arc119/tasks)

### A：NTT-friendly 数：枚举 b 即可

### B：一开始以为是贪心

这个 [评论](https://codeforces.com/blog/entry/90735?#comment-791680) 一下子顿悟了

### C：这种问题之前遇到了，竟然一下子不知道怎么做

意识到区间可行当且仅当它们的交错和（alternating sum）为 0，就简单了。

> 注意交错和有 n + 1 个值。


## [AtCoder abc201E](https://atcoder.jp/contests/abc201/tasks/abc201_e)

题意：树上任意两点的距离定义它们最短路上的边权异或和，求任意两点距离的距离之和。

做法：首先肯定要一位位的处理，但是我做的时候太早的一位位的处理导致特别慢，然后 TLE，后来细节优化终于 [2343ms](https://atcoder.jp/contests/abc201/submissions/22638931) 过了，然后发现别人特别快。再一分析，发现

$$
dist[i][j] = dist[1][j] \oplus dist[1][i]
$$

所以可以先把 `dist[1][i]` 求出来，再按位处理就很快了。


## [Atcoder arc117C](https://atcoder.jp/contests/arc117/tasks/arc117_c)

很有趣的一个堆积问题，关键在于转化成简单的四则运算，而当时没有想到这样的运算，可惜


## [Atcode abc196F](https://atcoder.jp/contests/abc196/tasks/abc196_f)

题意：给定一个 0-1 主串 S 和模式串 T，$|T| \leq |S|$ 问 $S$ 的长度为 $|T|$ 的子串和 $T$ 互异的位置数的最小值。

显然 $f[j] = \sum_{i = 0}^{|T| - 1} s_{i+j} \wedge t_i$，这是一个减法卷积，OK 结束。

> 如果字符串是小写字母组成，那么这个问题就可以枚举每一个字符，看相同的位置！然后累加 $O(26 \cdot |S| \log |S|)$



## [AtCoder ABC189F](https://atcoder.jp/contests/abc189/tasks/abc189_f)

从 0 位置出发，走到大于等于 n 的位置结束，每次平均概率在 [1, m] 步中选择步长来走，有 k 个坑，走到坑就回到起点 0。问结束前步数的期望是多少，如果无法结束就输出 -1。

做法：首先如果有连续 m 个坑（很好判断），必然无法结束，否则可以结束，我们设 `dp[i]` 表示从 i 出发的答案。显然 $dp[i] = 0, i \geq n$，我们从后往前跑，显然有状态转移，如果 i 位置有坑，那么 $dp[i] = dp[0]$, 否则 $dp[i] = (dp[i + 1] + \cdots dp[i + m]) / m  + 1$。这个后缀和，我们可以用个变量记录下来。因此 所有的 dp[i] 都是一个 $a + b dp[0]$ 的形式，然后到最后有 $dp[0] = a + b dp[0]$ 从而就求得了结果。


## [AtCoder arc111B](https://atcoder.jp/contests/arc111/tasks/arc111_b)：经典 2 选 1

大致 有 $n$ 个盒子，每个盒子有两个数，从中取去一个数，问最多可以取多少个不同的数。

数字为节点，盒子中的两个数连边（注意可能有重边），那个连通分支是树，那么答案就是连通分支节点数减 1，否则就是连通分支节点数。（树的情况容易证明，非树的情况总可以删边，删成只有树再多一条边的情况，然后也容易证明）


## [AtCoder arc111E](https://atcoder.jp/contests/arc111/tasks/arc111_e)

[教程](https://atcoder.jp/contests/arc111/editorial/546)


## [AtCoder abc184F](https://atcoder.jp/contests/abc184/tasks/abc184_f)：假 0-1 背包，Meet in Middle

题意：给定序列，求选择其中部分，使得它们和最大且不超过 t，这不就是 0-1 背包吗？但是数据范围 $0 \leq n \leq 40, 0 \leq a_i, t \leq 10^9$，此题即使是多重背包，也可以用下面各种方法来做

1. Meet in Middle，但是实现的时候可以有以下几种实现细节：
   - 用是 set 或 unordered set 存和更新，然后用双指针，整体复杂度 $O(n 2 ^{\frac{n}{2}})$
   - 用 Vector 存，之后排序（只需排序一个），然后用 `lower_bounded` 查找，复杂度同理
   - 用 Vector 存，保持有序，最后用双指针，复杂度 $O(2 ^{\frac{n}{2}})$
2. 先 dfs 找到一个较好的解，然后每次更新解，用来剪枝。


## [AtCoder ABC 183f](https://atcoder.jp/contests/abc183/tasks/abc183_f)：并查集 + map

题意：N 个节点，每个节点有一个值，然后 Q 次操作：`1 a b` 是将 a, b 所在的群合并，`2 x y` 求 $x$ 所在的群中，值为 $y$ 的个数。细节优化

- 尽量小的向大的合并，合并完小的记得清空
- `std::map` 优于 `std::multiset`
- `std::vector<std::map<int, int>>` 优于 `std::map<std::map<int, int>>`


## [AtCoder ABC 183e](https://atcoder.jp/contests/abc183/tasks/abc183_e)：经典 DP

题意：在 $n \times m$ 的格点中，有些点可以走有些不行，每次能往右，下或右下中的一个方向走任意步（但是中间不能有非法点），问有多少种从左上角到右下角的走法。
> 显然 DP，然后用类和优化

## [Atcoder ABC182F](https://atcoder.jp/contests/abc182/tasks/abc182_f)：找钱问题

给定 $n$ 种纸币，$1 = a_1 < a_2 < \cdots a_n$，且 $a_i | a_{i + 1}$，要买商品 $x$，那么可以给 $y \geq x$，找零 $y - x$，要求 $y$ 和 $y - x$ 的最少纸币表达中没有公共纸币。问所有的 $y$ 有没有种。
> 注意到 $y$ 和 $(y_1, \cdots, y_n)$，(其中 $y_i * a_i < a_{i + 1}$，且 $y = \sum a_i y_i$ 有一个一一对应。然后我们可以考虑 $x$ 的向量表达，然后再看 $y + x$ 和 $y$ 没公共非零项的做法。


## [Atcoder arc107C](https://atcoder.jp/contests/arc107/tasks/arc107_c)：并查集

首先，如果某两列和交换，那么给它们连边，那么只要任意两列可达，那么它们的位置最后就可以交换，也就是求每个连通分支的大小，直接广搜标记也可以做，当然了用并查集会更简单。


## [Atcoder arc107D](https://atcoder.jp/contests/arc107/tasks/arc107_d)：经典计算，DP 优化

将 $K$ 写成 $N$ 个形如 $2^{-i}, i \geq 0$ 之和（不计顺序），问有多少中写法。我们不妨将答案记作 `dp[n][k]`
那么显然 `dp[n][k] = dp[n][2k] + dp[n - 1][2k - 2] + \cdots dp[n - k][0]`（考虑取多少个 `1`，那么剩下的最少要以 $\frac{1}{2}$ 为最大值，那么就等价于剩下的数乘以 `2`)，所以令 `s[a] = dp[a][0] + dp[a + 1][2] + \cdots dp[n][2(n - a)]`，这样我们就能迅速求出 `dp[n][k]`


## [AtCoder arc106d](https://atcoder.jp/contests/arc106/tasks/arc106_d)：经典求和计算

对任意 $1 \leq x \leq K$ 求 $\sum_{1 \leq i < j \leq n} (a_i + a_j)^x$

注意到
$$
2 \sum_{1 \leq i < j \leq n} (a_i + a_j)^x = \sum_{i = 1}^n \sum_{j = 1}^n (a_i + a_j)^x - \sum_{i = 1}^n (2a_i)^x
$$
然后二项式展开即可。
> 若此题 $n$ 比较小，$k$ 比较大（$n$ 特别小时直接 $n^2 \log k$ 就没啥意思了），注意到二项式展开之后是个卷积形式，所以用 NTT 有 $O(nk + k \log k)$ 的做法。例如 $n < 3 \cdot 10^4, k < 10^5$ （时限 5s)

## [Atcoder ARC 104D](https://atcoder.jp/contests/arc104/tasks/arc104_d)

> E, F 题也是好题，不过不懂。

问题描述：对每一个 $m \in [1, n]$ 求满足 $\sum_{x \in S} (x - m) = 0$ 的集合 $S$ 的个数，其中 "集合" $S$ 是由 `1~n` 中元素构成，元素可重，重数不超过 k。这等价于说 $\sum_{x \in S} x = \sum_{x \in T} x$ 的个数乘以 $k + 1$，其中 $S$ 是由 `1 ~ m - 1` 构成，$T$ 由 `1 ~ n - m` 构成。

做法：我们设 `dp[i][j] 表示仅用 1 ~ i 中的数构成和为 j 的个数`，那么显然
$$
dp[i][j] = \sum_{t = 0}^k dp[i - 1][j - t * i]
$$
于是我们保存一下前缀和，那么就可以优化计算了。

## [AtCoder ACL2f](https://atcoder.jp/contests/abl/tasks/abl_f): 包容排斥原理 + NTT

## [AtCoder ACL2e](https://atcoder.jp/contests/abl/tasks/abl_e)：线段树模板题


## [AtCoder ABC178e](https://atcoder.jp/contests/abc178/tasks/abc178_e)：Manhattan 距离

给定一堆点，求它们的 Manhattan 距离中最大值

> 注意到其实任意两点的距离等于，它们到最左上角和到最下角的距离的距离差的最大值。


## [Atcode](https://atcoder.jp/contests/aising2020/tasks/aising2020_f)：经典生成函数题

题目很容易转化成，满足所有$(a_1+\cdots+a_5)+2(b_1+\cdots+b_5) \leq N$的$a_1 \cdots a_5$之和，其中$a_i,b_i$ 均为非负整数

我一开始把 5 看作变量，从 `1,2,3` 一直推出 5 的公式，贼麻烦。后来  [querty20002](https://codeforces.com/profile/querty20002) 给出了生成函数做法的 [题解](https://codeforces.com/blog/entry/79978#comment-659438)。答案唯一的依赖于 $N$，即可认为答案是关于 $N$ 的数列，那么它的生成函数即为：
$$
\begin{array}{cl}
\sum a_1a_2a_3a_4a_5(N) x^N &= (x+2x^2+\cdots)^5 (1+x^2+x^4+\cdots)^5 (1+x+x^2) \\
&= (\frac{x}{(1-x)^2})^5 (\frac{1}{1-x^2})^5 \frac{1}{1-x} \\
&=  \frac{x^5(1+x)^{11}}{(1-x^2)^{16}}\\
&= x^5(1+x)^{11} \sum_{n} \binom{n+15}{15} x^{2n}
\end{array}
$$
所以答案就是 $\sum_{i=N\%2}^{11} \binom{11}{i} \binom{\frac{N-i-5}{2}+15}{15}$，所以我们选择 Python 交题 0.0