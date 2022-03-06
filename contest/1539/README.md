# [Codeforces Round #727 (Div. 2)](https://codeforces.com/contest/1539)

## A: 不太容易的 A

注意到后面的答案必然是 $\frac{t}{x}, \cdots, 0$. 因此 最终答案分情况讨论即可

> 有一个地方少写了 `LL` 贡献了一次 WA：`1LL * a * b + c * d`（怎么避免再出这种低级错误呢）

## B：真签到，前缀和

## C：相邻位置填入数字

> 这个其实可以做成多次查询的

## D：很有意思的买东西问题

我们先按照 $b$ 排序，注意到如果当前不能降价，那么不妨选最后的充数

## E：满足给定范围

jiangly 是从后往前做的

## F：这一类问题好常见啊

但是我不会 [2qbingxuan](https://codeforces.com/profile/2qbingxuan) 的[代码](https://codeforces.com/contest/1539/submission/120093602) 很值得借鉴

存编号，带最大最小值支持区间加法的线段树即可（其实比赛的时候我大致想到了这个做法，以为复杂度不行就没搞）。
