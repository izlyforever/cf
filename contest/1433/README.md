## [Codeforces Round #677 (Div. 3)]((https://codeforces.com/contest/1433)

### G: 将某条边的权值置零下最短路径

我一开始以为是缩点... 想太多了，做法就是先求出任意两点的距离，然后边 `x -> y` 置零可以看成 `a -> b` 多了两种选择 `a -> x - > y - > b` 和 `a -> y -> x -> b` 就好了。

> 用堆优化 Dijkstra 会更快一些，用 priority_quque 比 set 快一些。不过 set 比 priority_quque 方便很多（好遍历删除等操作）。
