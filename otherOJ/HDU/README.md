## [百度之星 2021 初赛](http://bestcoder.hdu.edu.cn/contests/contest_show.php?cid=998)

### 1003

我们可以直接 DP，答案，注意到每次操作仅仅会影响两个地方的答案

### 1004

不妨假设 $a \geq b$，$c = a - b$，然后一个是 $c$ 的最小大于 1 的因子，一个是 $c$，但是为了合理性，必须要 $a \geq 2$，且 $c = 0$ 或者 $c > 1$


### 1005

这是一个公式推导题：

$$
E_i = \left\{ \begin{array}{ll} \frac{\sum_{j = 1}^{i - 1} E_j}{i - 1} + 1 & i > y \\
\frac{\sum_{j = i + 1}^n E_j}{n - i} + 1 & i < y\end{array} \right.
$$

注意到 $E_y = 0$

若 $i > y$, 则 $E_1 + \cdots E_{i - 1} = (i - 1) (E_i - 1)$，所以
$$
(i - 1)(E_i - 1) + E_i = i (E_{i + 1} - 1)
$$
即 $E_{i + 1} = E_i + \frac{1}{i}$

若 $i < y$, 则 $E_{i + 1} + \cdots E_n = (n - i) (E_i - 1)$，所以 
$$
E_i + (n - i) (E_i - 1) = (n - i + 1)(E_{i - 1} - 1)
$$

即 $E_{i - 1} = E_i + \frac{1}{n - i + 1}$

又

$$
y (E_{y + 1} - 1) = E_1 + \cdots E_y = (y - 1) E_{y - 1} + \sum_{i = 1}^{y - 2} \frac{i}{n - i}
$$

且

$$
(n - y + 1)(E_{y - 1} - 1) = E_y + \cdots E_n = (n - y) E_{y + 1} + \sum_{i = 1}^{n - y - 1} \frac{i}{n - i}
$$


> 直接手推要推的想吐，还不如设变量直接解，再也要考虑 $y$ 在边界的情况

设 $A_i = \sum_{j = 1}^i \frac{j}{n - j}$，解二元一次方程即可得到 $E_{y - 1}$ 和 $E_{y + 1}$ 即可

### 1006

没想到这个题 $O(n \log n)$ 用 set 拼接都不行，一定要 $O(n)$ 算法

首先用一个 vis 标记是否为 1，然后再看左边可延伸的地方和右边可延伸的地方，然后注意处理下细节即可


> 同样的代码 BestCoder AC，HDU TLE
> 
### 1008

这 TMD 叫猎人杀？狼人就杀一次人？我完尼玛

## [hdu 4747](http://acm.hdu.edu.cn/showproblem.php?pid=4747): MEX

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
