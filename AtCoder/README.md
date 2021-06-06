2021.6.6 后开始在此保存 AtCoder 代码


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

