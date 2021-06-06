## 牛客

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


## HDU

### [hdu 4747](http://acm.hdu.edu.cn/showproblem.php?pid=4747): MEX

求 $\sum_{1 \leq L \leq R \leq n} MEX(L, R)$)，其中 $MEX(L, R)$ 为使得 $a_L, a_{L + 1} \cdots, a_{R}$ 中没出现的最小自然数

> 同理与上面做法，代码不写了，懒得写线段树。

> 有的 MEX 定义包含 0, 有的不包含，无所谓啦。