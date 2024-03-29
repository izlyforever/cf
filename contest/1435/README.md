## [Codeforces Round #679 (Div. 2, based on Technocup 2021 Elimination Round 1)](https://codeforces.com/contest/1435)

### C：经典选择问题

题意大致可以转化成：有 $n$ 个人，每个人有 $m$ 个值可以选择，问如何选择才能使得他们的最大值减最小值最小。

做法就是把所有可能的选择进行排序（二维，一维存值，一维存人），然后看所有人至少一次选择的时候最大值和最小值的差是多少。相当于左右两个指针在跑，复杂度为 $O(nm)$

### D：经典进出问题

将 $1 ~ n$ 个元素进行加入和提出操作（每个元素一次，共 $2n$）次，并且每次出的是当前集合中最小的值。
给定一个进出序列，和出的时候的元素值，求进的元素值（不合理的输出：NO)。

> 注意到每出一个元素，那么集合中剩下的元素都要大于出的元素，但是这个信息可以由顶元素上加限制来承载。当在加入一个新元素后，这个限制又被暂时的隐藏了。所以存在当前顶元素上是特别优质的做法。

> 此题一开始题意理解有点问题，最后竟然还 PA，结果最终评测 WA 了。
