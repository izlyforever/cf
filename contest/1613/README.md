# [Educational Codeforces Round 118 (Rated for Div. 2)](https://codeforces.com/contest/1613)

## A

先比较 0 的个数，然后一点点的乘以 10，每次不叫大小，注意一下 0 的个数一样的情况

## B

取最小值和其它任意值即可

## C

二分答案即可

## D

注意到 $x_i - \text{MEX}(x_1, \cdots, x_i)| \leq 1$ 等价于 $\text{MEX}(x_1, \cdots, x_i) = x_i \pm 1$。另外注意到 MEX 是单调递增的。但是 $Mex(S) = x$ 只有两种情况 $\max(S) = x - 1$ 或 $\max(S) = x + 1$（它们必然都满足$S$ 中包含 $\{0, \cdots, x - 1\}$）。那么我们按照这个递推即可。
