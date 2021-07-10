
## [The 18th Zhejiang Provincial Collegiate Programming Contest](https://codeforces.com/gym/103055)：陈靖邦的高质量一场

### A：签到题

### C: 通过比较距离判断

### D：特别经典有意思的最短路问题

题意是连的边必须满足一个编号是另一个的前缀。这样我们用 `dist[u][dep]` 表示 `u` 到 `u >> len[u] - dep` 的距离，显然 $len[u] \geq dep$ 才有意思。然后任意一点的距离就是看它们到它们的公共前缀之间的距离之和的最小值。

> 注意再 Dijkstra 的时候，我们找边要往下找!

### F：经典数学问题！要不慌不忙推理即可

枚举 n 的值，然后整除分块加速即可

### L：水题

> 我一开始以为题目给的是 S，导致无从下手

### M：推理发现，答案始终为 0