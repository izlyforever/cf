## [Educational Codeforces Round 105 (Rated for Div. 2)](https://codeforces.com/contest/1494)

### E：假图论，真找规律

首先注意到如果 u 到 v 和 v 到 u 有相同的 label，那么必然 YES，否则如果 u 到 v 和 v 到 u 都有边，那么偶数情况必然 YES，奇数情况 NO。

## F：拓展 Euler 路

先走 Euler 路，然后走两点折返的路径（先删去两点折返路，细节就是删完之后要保证连通）

> 我最后攻击了[自己的代码](https://codeforces.com/contest/1494/submission/108962618)...

> 以上代码还有很多可优化的地方，不过暂时没时间也没必要优化。[最终无比丑陋的代码](https://codeforces.com/contest/1494/submission/108997150)
