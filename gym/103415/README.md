# [The 2021 CCPC Guangzhou Onsite](https://codeforces.com/gym/103415/)

## K

$$
\sum_{1 \leq s_1, \cdots, s_n \leq m} [\gcd(s_1, \cdots, s_n) \leq q] \cdot [\text{lcm}(s_1, \cdots, s_n) \geq p] \cdot \prod_{i = 1}^n s_i
$$

此题求上述表达式模 998244353，第一眼看上去以为是一个生成函数的 $n$ 次方前面的系数，但是怎么想都想不通，后来看了题解发现题解也只是一点点的剖析得到的结果。按照题解的做法

首先定义 $S = (s_1, \cdots, s_n)$, $F(S) = \prod_{i = 1}^n s_i$, $Z_m = \{S  \mid 1 \leq s_i \leq m \}$ 将其划分为 $Z_m = A_m \cup B_m \cup C_m$(注意是不交并)，其中 
- $A_m = \{S \mid \gcd(S) \leq q, \;\text{lcm}(S) \geq p \}$
- $B_m = \{S \mid \gcd(S) > q \}$
- $C_m = \{S \mid \gcd(S) \leq q, \; \text{lcm}(S) < p \}$

注意到我们要求的答案是 
$$
\sum_{S \in A_m} f(S) = \sum_{S \in Z_m} f(S) - \sum_{S \in B_m} f(S) - \sum_{S \in C_m} f(S)
$$

而 $\sum_{S \in Z_m} f(S) = (1 + \cdots + m)^n$，我们接下来求其它两个

$$
\sum_{S \in B_m} f(S) = g_{q + 1}(S) + \cdots + g_m(S)
$$

其中 $g_k(S) = \sum_{S \in Z_m, k = \gcd(S)} f(S)$

我们再定义 $h_d(S) = \sum_{S \in Z_m, d | \gcd(S) } f(S) = \sum_{d | k} g_k(S)$

注意到 $h_d(S) = d^n \sum_{S \in Z_{m / d}} f(S)$

既然如此，我们只需把 $\sum_{S \in B_m} f(S)$ 由 $g_i(S)$ 的线性组合变成 $h_i(S)$ 的线性组合即可

$$
\sum_{S \in C_m} f(S) = \sum_{d \leq q} \sum_{l \leq p - 1, d | l} \sum_{S \in E_{m, d, l}} f(S)
$$

- 其中 $E_{m, d, l} = \{ S \mid S \in Z_m, \gcd(S) = d, \text{lcm}(S) = l \}$，注意到由于 $d, l$ 本身的限制，$E_{m, d, l}$ 与 $m$ 无关。
- $(d, l)$ 确定了 $S \in E_{m, d, l}$ 的 $X_p(S), Y_p(S)$ 分别表示在素数 $p$ 的指标的最小最大值，注意 $s_i$ 只收到每一个素因子指数的影响，可以在 $X_p(S)$ 和 $Y_p(S)$ 之间任意取值，只要有两个包含他们即可
- $\{ S \mid X_p(S) = x, Y_p(S) = y \} = \{ S \mid X_p(S) \geq x, Y_p(S) \leq y \} - \{ S \mid X_p(S) \geq x + 1, Y_p(S) \leq y \} - \{ S \mid X_p(S) \geq x, Y_p(S) \leq y - 1 \} + \{ S \mid X_p(S) \geq x + 1, Y_p(S) \leq y - 1 \}$
- 所以利用包容排斥原理和乘法分配律，求每一个素因子 $p$ 对答案的贡献，最后相乘即可
- 可以先预处理所有三元组 $\{p, X_p(S), Y_p(S) \}$ 的贡献（这样存储会比较麻烦）

$$
f(x, y) = |\{ S \mid X_p(S) \geq x, Y_p(S) \leq y \}| = (p^x + \cdots + p^y)^n
$$

所以其实我们只需预处理一下 $p^x$ 的前缀和即可

实现的一些说明

- 注意 $p^x + \cdots + p^y < 2 m$，所以可以不做取模的操作，前缀和减的时候也不需要，我们可以预处理出所有的 $i^n, i < 2m$
- 我们需要预处理对每一个 $p$，求最大的 $y$ 使得 $p^y <= m$，然后再预处理前缀和，外层的幂次后面再处理
- 我们可以只考虑 $l / d$ 的答案即可，这样就不用存那么多值了
- 应该尽量一个循环一个模块，这样可以利用高速缓存
- 整体复杂度可达到 $O(m \log m + m \log n)$
- 目前 2021.11.18 15:20:00 78ms 最佳

~~貌似我们完全可以不用考虑 $Z_m, B_m$ 直接去处理 $C_m$ 类似的情况啊，直接枚举 $(d, l)$ 啊~~，这样不行的原因是 lcm 的值没法控制


[Möbius 反演的做法](https://blog.csdn.net/qq_47903865/article/details/121323986?utm_source=app&app_version=4.18.0&code=app_1562916241&uLinkId=usr1mkqgl919blen) 原文（错误太多了，还是看我这里的吧）作者直接包容排斥，感觉还是题解的排斥做法更好

- $\text{lcm}(S) | x$ 的答案为 $h(x) = (\sum_{d | x} d)^n$
- $\text{lcm}(S) = x$ 的答案为 $g(x) = \sum_{d | x} \mu(d) h(\frac{x}{d})$
- $\text{lcm}(S) = x, \gcd(S) = 1$ 的答案为 $f(x) = \sum_{d | x} \mu(d) d^n g(\frac{x}{d})$（这里应用了可乘函数的逆公式，以及下面性质）
- $\text{lcm}(S) = xt, \gcd(S) = t$ 的答案为 $t^n f(x)$
- 无限制的答案为 $H(m) = \left(\frac{m(m + 1)}{2} \right)^n$
- $\gcd(S) = 1$ 的答案为 $G(m) = \sum_{d = 1}^m \mu(d) d^n H(\lfloor \frac{m}{d} \rfloor)$(这里应用了可乘函数的逆公式，以及下面性质)
- $\gcd(S) = t$ 的答案为 $F(t) = t^n G(\lfloor \frac{m}{t} \rfloor)$

所以最终答案就是 

$$
H(m) - \sum_{i = q + 1}^m F(i) - \sum_{i = 1}^q i^n \sum_{j = 1}^{\lfloor \frac{p - 1}{i} \rfloor} f(j)
$$

注意到 $F(t)$ 的值和 $m$ 强绑定（$\lfloor \frac{m}{t} \rfloor$ 最多只有 $2 \sqrt{m}$ 个值，然后可以用整除分块），因此计算所有 $F(t)$ 计算量为 $O(m)$，所以复杂度 $O(m \log m + m\log n)$

