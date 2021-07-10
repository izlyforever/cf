
# [计划完成 集训队互测所有题目](https://vjudge.net/problem#OJId=LibreOJ&probNum=&title=&source=%E9%9B%86%E8%AE%AD%E9%98%9F%E4%BA%92%E6%B5%8B&category=all)


## [2018 集训队互测 Day 3：蒜头的奖杯](https://vjudge.net/problem/LibreOJ-2476)

由 Mobius 反演：$f(n) = \sum_{d | n} f'(d) \equiv \sum_{d | n} (f \star\mu)(d)$ 

$$
f_{\gcd(i, j)} = \sum_{d | i, d |j} f'(d)
$$

我们记

$$
f''(x) = \sum_{x | i}^n f(i)
$$

则


$$
\begin{aligned}
ans(n) = & \sum_{i = 1}^n \sum_{j = 1}^n \sum_{k = 1}^n A_i B_j C_k D_{\gcd(i, j)} E_{\gcd(i, k) F_{\gcd(j, k)}} \\
=& \sum_{d_1 = 1}^n D'(d_1) \sum_{d2 = 1}^n E'(d_2) \sum_{d3 = 1}^n F'(d_3) \sum_{d_1 | i, d_2 | i}^n A_i \sum_{d_1 | j, d_3 | j}^n B_j \sum_{d_2 | k, d_3 | k}^n C_k \\
=& \sum_{d_1 = 1}^n D'(d_1) \sum_{d2 = 1}^n E'(d_2) \sum_{d3 = 1}^n F'(d_3) A''([d_1, d_2]) B''([d_1, d_3]) C''([d_2, d_3])
\end{aligned}
$$

> 这个题甚至还能再多一个指标，并且可以让上界不一样，但是无所谓，可以通过补 0，让其一致！我的天。

[提交记录](https://vjudge.net/solution/31451017)，全排列的方式太慢不建议使用

然后同样的是三元图计数即可搞定，再多一个指标就用四元图计数搞定（更麻烦一点）


[另一种做法](https://www.cnblogs.com/ImagineC/p/10557379.html)，不拆那么多，复杂度为 $O(n \sqrt n \log \log n)$。


$$
\begin{aligned}
ans(n) = & \sum_{i = 1}^n \sum_{j = 1}^n \sum_{k = 1}^n A_i B_j C_k D_{\gcd(i, j)} E_{\gcd(i, k) F_{\gcd(j, k)}} \\
=& \sum_{k = 1}^n C_k \sum_{i = 1}^n \sum_{j = 1}^n A_i B_i D_{\gcd(i, j)} \sum_{p | i, p | k} E'(p) \sum_{q | j, q | k} F'(q)\\
=& \sum_{d = 1}^n \sum_{xy <= \frac{n}{d}, \gcd(x, y) = 1} E'(xd) F'(yd) C''(xyd) \sum_{ix \leq \frac{n}{d}} \sum_{jy \leq \frac{n}{d}} A_{ixd} B_{jyd} D_{d \cdot \gcd(ix, jy)}\\
\end{aligned}
$$

按照 [imageC](https://www.cnblogs.com/ImagineC) 的做法：令 $P_i = E'(id), Q_i = F'(id), R_i = C''(id), S_i = A_{id}, T_i = B_{id}, W_i = D_{id}$

原式等价于求

$$
\sum_{d = 1}^n \sum_{xy \leq m, (x, y) = 1} P_x Q_y R_{xy} \sum_{ix \leq m} \sum_{jy \leq m} S_{ix} T_{jy} W_{(ix, jy)}
$$

当 $d, x, y$ 都固定时，我们需要求 

$$
\begin{aligned} 
&\sum_{ix \leq m} \sum_{jy \leq m} S_{ix} T_{jy} W_{(ix, jy)} \\ = & \sum_{ix \leq m} S_{ix} \sum_{jy \leq m} T_{jy} \sum_{r | ix, r | jy} W'(r)  \\ = & \sum_{jy \leq m} T_{jy} \sum_{r | jy} W'(r) \sum_{r | ix} S_{ix}
\end{aligned}
$$

> 注意到我们总能让 $x \leq \sqrt{m}$，否则 $x, y$ 互换一下

## [凸优化借助凸包解决](https://vjudge.net/problem/Kattis-mobilization)

> 详细解释放在 [izlyforever](https://izlyforever.com/spookywooky/)

## [ZOJ 3820](https://vjudge.net/problem/ZOJ-3820)：树的重心 + 直径

题意：在一棵树上选择两个点，使得任意点到这两点的最小值的最大值最小。
> 如果仅仅选择一个点，那么这个问题就是树的重心。
> 
> 对此情况，将直径按照中点切开，然后分别求两颗子树的中心, [参考资料](https://blog.csdn.net/ok_again/article/details/40043197)

证明：如果 u,v 是满足条件的两个点，那么把他们沿着中间切开必然最优，然后反证它们在树的直径上。

## [阶乘](https://vjudge.net/problem/SPOJ-FACTMODP)

min25 的毒瘤 $\sqrt{n} \log n$ 阶乘题

