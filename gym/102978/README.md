
## [XXI Opencup GP of Tokyo](https://codeforces.com/gym/102978)

> 一场不看题解几乎一题不会的场

### A：经典转化

即使看了题解，说等价于删除左或者删除右，我一开始还是没懂，后来注意到每次有 2N - 2 种选择之后就懂了。后来就是删除然后递推了（个人认为是平凡的）

### C：经典 FFT（神仙题）

这不看题解咋做呀，看了题解也要搞半天。题解是这样审的：

首先考虑这个问题：给定非负整数 $W, A, B$ 问从格点 $(0, 0)$ 到格点 $(W, AW + B)$ 有多少条路径（只往右上放走）并且不许在直线 $y = Ax + B$ （严格的）上方。

可以证明答案是 $\binom{W + AW + B}{W} - A \binom{W + AW + B}{W - 1}$。这个证明完全类似 Catalan 数的计算。

接下来，我们给定非负整数 $H, W, A, B$ 满足 $0 \leq B \leq AW + B \leq H$，考虑从 $(0, 0)$ 到 $(W, H)$ 的格点路径。我们定义路径的权重为经过形如 $(x, Ax+B)$ 的点的个数。我们把所有路径的权重和记作 $f(H, W, A, B)$。考虑 $z = f(H, W, A, B) - A \cdot f(H + 1, W - 1, A, B)$，显然

$$
z = \sum_{0 \leq x \leq W} |(0, 0) \to (x, Ax + B)| \cdot (|(x, Ax + B) \to (W, H)| - A \cdot |(x, Ax + B) \to (W-1, H+1)|)
$$

考虑从 $(0, 0)$ 到 $(W, H + 1)$ 的路径个数。因为 $H + 1 > AW + B$，因此总存在最小的 $x$ 使得路径经过 $(x, Ax + B)$ 并且此后都严格在直线 $y = Ax + B$ 之上。把这后一段往下带一手，那么就是不严格在直线之上了（我们强行演算也可以）。即 $z = \binom{W + H + 1}{W}$，因此 

$$
f(H, W, A, B) = \sum_{0 \leq i \leq W} \binom{W + H + 1}{i} A^{W-i}
$$

> 注意到上述结果于 B 无关，因此我们不妨取 $B = 0$ 这很重要！。

我们回到原问题：我们需要计算 $\sum_{1 \leq x \leq N} g(x)$ 其中 $N = \lfloor \frac{R}{B}\rfloor$，$g(x) = (R + 1 - Bx) f(R, B, x)$
注意到 $(x, y)$ 会被直线 $Ax + B$ 经过 $\frac{y}{x}$ 次！因此就是上述计算！

卡在时间上过了，差点超时。

### D：经典 FFT（神仙题）

官方题解说是使用 [Tellegen’s Principle](BoLeSc03.pdf)，但是 [jtnydv25](https://codeforces.com/blog/entry/88215?#comment-766276) 给了更简洁的做法。[SevenDawns](https://codeforces.com/profile/SevenDawns) 的 Talk。
利用 [多点求值新科技](https://jkloverdcoi.github.io/2020/08/04/转置原理及其应用/) 类似的推出，我们需要我们需要求解 
$$
[x^0] Mult(T(x), \prod_{i = 1}^k (x - B_i)
$$

其中 $T(x) = \sum_{i = 1}^n \frac{C_i}{1 - A_i x}$。我们记 $P_{[L, R]} = \prod_{i = L}^{R} (x - B_i)$。我们分治就可以得到答案

$$
Mult(T(x), P_{[L, R]} = Mult(Mult(T(x), P_{[L, M]}), P_{[M + 1, R]})
$$

代码太长不贴了。


### G: 可选多堆的二人公平博弈

问题转化成求多元多项式的 k 次方的问题。这里多元多项式是比较特殊的，而且它的乘法也比较特殊。即

$$
ans_{(c_1, c_2, \cdots, c_N)} = \sum_{c_i \equiv (a_i + b_i) \mod X} A_{(a_1, a_2, \cdots, a_N)} B_{(b_1, b_2, \cdots, b_N)}
$$

它是 fwt 变换可解决的一种。当然了这也可以如果 $N = 1$ 这就是实打实的卷积，并且这个长度不可拓展！那么我们可以每一维做一次 DFT。


### I

此题真的把我折磨吐了（最后开始 Coach 模式终于解决了）。注意到最后一个元素的特殊性！
