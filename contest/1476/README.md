## [Educational Codeforces Round 103 (Rated for Div. 2)](https://codeforces.com/contest/1476)

### C：类似于把 a, b 变成 a - b 问题（代码自解释）

题目中 3 个袋子可以换成 $m(m \geq 3)$ 个袋子。

### D：模拟题

题意：$n + 1$ 个点排成一排，中间有 n 跳有向边，问从 i 点出发最多可以经过多少个点（没走一次，所有边都会反向一次）

做法：首先，如果不反向，显然可以从左到右，从右到左跑两次得到结果。现在反向了，我们可以把奇数边反向，或者把偶数边反向，两个都需要，用数组好标号。注意逻辑要清晰了，怎么存都想清楚了，列好式子再写代码就会很优雅。

> ~~下面代码写的相当优雅！~~ 看了 [WZYYN 的代码](https://codeforces.com/contest/1476/submission/105866936) 发现他比我这代码优雅多了。。直接 `f[0], g[0]` 表示往前往后没改变时的答案，`f[1], g[1]` 表示改变了的答案。然后递推就好了。

