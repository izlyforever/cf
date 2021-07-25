# [Codeforces Global Round 15](https://codeforces.com/contest/1552)

## A

排序比较不同即可

## B

根据偏序关系求最大值，然后看它是否大于所有的数

## C

由于交叉越多相交的点越多，于是我们顺序标记 $k, k + 1 \cdots, n - 1$ 两边，然后对每个标记计算依次结果，每个标记有两个值。根据两个值是否是仅出现一次来判断是否加入

