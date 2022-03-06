## [Codeforces Round #678 (Div. 2)](https://codeforces.com/contest/1436)

### E: MEX

求 $MEX(MEX(L, R)_{1 \leq L \leq R \leq n}$)，其中 $MEX(L, R)$ 为使得 $a_L, a_{L + 1} \cdots, a_{R}$ 中没出现的最小正整数。

做法：先求出所有 MEX(i, n)，这是能在 $O(n)$ 时间复杂度解决的（因为 MEX 会随着 i 递减而增大，并且值域不超过 $n$）。然后我们删除尾部的点，那么在从右往左首次出现 $Mex(i, n) > a[n]$ 的 `pre[n] + 1 ~ i` 这一段的值都要改成 `a[n]`,这里 `pre[x]` 表示 `x` 位置前一个值为 `a[x]` 的位置。那么区间线段树就搞定了。
> 没在比赛时候写出，不想写了！
