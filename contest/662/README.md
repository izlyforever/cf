## [CROC 2016 - Final Round [Private, For Onsite Finalists Only]](https://codeforces.com/contest/662)：私密比赛无法提交

### C：状态压缩 DP + FWT 模板

给定 $n \times m$ 的 0-1 方阵，可以取反一些行和列使得最后 0 的数列最小。

> 首先注意到 $n < 20$，我们可以把每一列看作一个状态 `i` ，并且结果跟列的顺序无关。我们可以记录下初始情况每种状态数 C[i] 量。
> 并且每一种状态 `i` 对答案的贡献显然就是它的 0, 1 个数的最小值记作 `g[i]`。
> 对于每一个行取反 S, 其实就是将一个状态 i 变成 状态 `i ^ S`
> 所以每一种行取反 S，最终的答案 $\displaystyle F(S) = \sum_{i} C[i] \cdot g[i \wedge S] = \sum_{i \wedge j = S} C[i] \cdot g[j]$ 
