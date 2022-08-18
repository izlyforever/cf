# [Codeforces Round #814 (Div. 2)](https://codeforces.com/contest/1719)

## A

考虑和的奇偶性

## B

考虑 k mod 4 之后的值，
- 如果是奇数，那么自然 `(奇数 + k）* 偶数` 是 4 的倍数
- 如果是 0，那么所有的奇数必须配上偶数，自然会有不是 4 的倍数的情况，所以不行
- 如果是 2，那么 $(4k + 2 + 2) * (4k + 1)$ 是 4 的倍数 $(4k + 1 + 2) * (4k)$ 也是 4 的倍数


## C

> 又 TMD 读错题，我以为要算参与比赛的次数（c1.cpp)，搁那 debug 半天。

显然最大值到达最左边之后就稳定了，只有他赢，因此可以对 $k$ 排序，用个数组记录各个 index 赢的次数，然后离散解决就好了。

## D

首先注意到 4 个一起处理 和 分2个2个处理代价是一样的。而单个处理也可以和它相邻的一起处理，代价也是一样的。所以我们可以一致记录当前为结尾的各个后缀的异或和。而这个自然是可以做成单次 $O(\log n)$ 的（利用水涨船高技术）。
