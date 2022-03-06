
## [UFPE Starters Final Try-Outs 2021](https://codeforces.com/gym/103076)

### B：直接暴力

我这写法优雅的不行，可以让题目中 N 放宽到 25，且不用对 S 有任何限制。（写的时候没输入 x，然后 WA 几次才发现，也是服了自己了）

### D 简单二分

### H. 8 Game 超级经典的游戏！假搜索，真 Dijkstra

> 注意要保存成字符串节省空间，还有就是用排列缩小编号

### I：裸动态开点线段树，一开始以为 multiset 能过（pb_ds 无敌）

> 应该 long long 的地方 写成了 int 导致 WA 两发 很不应该


multiset 不能过是因为 distance 求的时候是 $O(N)$ 的，然而 `pb_ds`就提供 $O（\log n)$ 的操作。但是 pb_ds 默认不支持 multiset 的形式，于是用 `std::pair<int, int>`， 后面带指标就可以变得像 multiset 了。

> 竟然比我用动态开点线段树快，我不能接受
