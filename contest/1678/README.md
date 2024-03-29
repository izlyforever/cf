# [Codeforces Round #789 (Div. 2)](https://codeforces.com/contest/1678/)

> 天胡开局，打的还行，E WA 了一发，不然必然第 8

## A

看非零元素的个数，然后再看是否有零，是否有重复元素

## B

只需看 $s[2i]$ 和 $s[2i + 1]$ 是否一致，如果不一致个数加1，此时最终数据任意，否则个数不变最终数据固定，所以看固定数据交替的次数及时另一个答案

## C

记 $x[i][j]$ 表示 前 $i$ 个位置中小于 $j$ 的个数
记 $y[i][j]$ 表示 后 $i$ 个位置中小于 $j$ 的个数

枚举 $b, c$ 的位置即可，整体复杂度 $O(n^2)$，注意答案会超 int

## D

注意纵向，$i$ 和 $i + m$ 有相同的纵向，然后对于 $j$ 和 $j + m$ 有相同的布局，其它的看代码一目了然

## E

这显然可以搞出很多联通分支，对于每个联通分支，然后一大一小交替最优，然后注意到最后联通分支大小为奇数时最后的一个数无论取什么都不改变答案，因此，干脆就去掉这个节点好了

## F

- 首先注意到 $v$ 和 $S$ 是一一对应的
- 每次操作后，都会把前面的最大值移到最右边，具体的说，假设当前为 $v = (v_1, \cdots, v_n)$，那么下一步 $v' = (v'_1, \cdots, v'_n)$, 其中$v'_n = 0$, $v'_i = \max(v_{i + 1} - 1, 0)$

