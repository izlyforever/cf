## [Codeforces Round #613 (Div. 2)](https://codeforces.com/contest/1285)


### C：找出使得$\max(a,b)$最小并使得$lcm(a,b)=x$的最小$a,b$

> 将 $x$ 分解素因子可知，$\max(a,b)$ 最小的前提是，$\gcd(a,b)=1$，又因为 $x$ 的因子个数不超过$2\sqrt{x}$，搞定

> 本来不想写这个题，但是由于下题都是 `lcm` 问题，又是同一场，所以就记录一下

### D：比赛的时候想到了，但是怕复杂度过补了，能过复杂度是因为每个元素 $a$ 最多递归 $\log a$ 次


### F：一道很秀的 lcm 题，计算 $\displaystyle \max_{1\leq i< j \leq n} lcm(a_i,a_j)$

> 参考这里：[https://www.xht37.com/codeforces-round-613-div-2-%E9%A2%98%E8%A7%A3/#Classical](https://www.xht37.com/codeforces-round-613-div-2-题解/#Classical)

通过加入 $a_i$ 的所有因子，我们可以改成计算 $\displaystyle \max_{\gcd(a_i,a_j)=1} a_ia_j$，我们将 $a_i$ 从大到小排序，然后开始遍历，用堆 s 保存之前的内容，注意到，如果堆 s 中有一个元素 t，跟当前需要遍历的元素 $a_i$ 互素，那么小于 s 中小于 $t$ 的元素讲不再能为结果做贡献。因此可以踢出栈中，现在问题是我们如何快速的记录**堆 $s$ 中是否有与$a_i$ 互素的元素**。记 $c_i$ 为堆中是 $i$ 的倍数的元素个数，那么堆中和$x$互素的个数为 $cop = \sum_{d|x} \mu(d) c_d$，这是因为包容排斥原理，首先所有数都是 1 的倍数，然后减去和 $x$ 的最小公约数为素数的，在加上和 $x$ 的最小公约数为两个素数相乘...。若 $cop$ 不为 0，那么就一个个的剔除，剔除的时候可以计算一下乘积（虽然不一定互素，但是不会影响的最终结果）
