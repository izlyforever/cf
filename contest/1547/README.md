# [Codeforces Round #731 (Div. 3)](https://codeforces.com/contest/1547)

## A

特判一下 $F$ 是否在 $A, B$ 的水平或竖直的线上

## B

这题长度不超过 26，如果长度超过 26 怎么做呢？ DP 还是递归呢？

> 如果两头有相等的情况，那么就看是否有一段连续的 $a-z$ 轮换序列，如果有就剪掉，否则就不行，注意看例子： `bacdefghijklmnopqrstuvwxyzab`

## C

贪心即可

## D

贪心


## E

单调栈

## F

倍增 $O(n \log n \log n)$, 不依赖数值范围

> 官方题解的做法是基于数值范围的

