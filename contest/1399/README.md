## [Codeforces Round #661 (Div. 3)](https://codeforces.com/contest/1399)


### D: `01`序列分组，使得各组相邻元素不同（主要考察复杂度，超级容易 TLE）

> 可以存储当前 `1` 和 `0` 的个数，然后一直跑，就是 $O(n)$ 复杂度了


### E1：dfs 建树，然后就知道每条边的权重，然后有限队列贪心即可，注意是所有叶子节点到根的距离和

### E2: 同 E1，只是贪心的时候，枚举费用为 2 的边的个数

### F:  区间 dp 问题

> 用 `f[m]` 表示从 `a[i]` 的左边界到，`m` 的区间个数(是被一个大的覆盖了的区间，size 一般不为 1）
