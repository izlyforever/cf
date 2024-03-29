# [Codeforces Round #765 (Div. 2)](https://codeforces.com/contest/1625)

## A

就是每一位的计数，然后看是否个数大于 $\frac{n}{2}$

## B

看相同数的最小间距

## C

这题直接 DP 即可


## D

这题的思路完全类似于 <https://codeforces.com/contest/1616/problem/H> ，可以模仿来做，然后注意到我们可以让 $k$ 自减去 1，这样我们就能更快的判断。当然了 $k = 0$ 就全选。显然排序后分组，不同组必然可以任意选择，相同组最多可以选两个（所以返回能否选择两个），对每组按照当前位是否为 0 再次分组。然后看 $k$ 的此位是否为 0，若为 0，任意两个都可以，若为 1，递归下去。找到两个可行的即可。

> 我竟然因为判断顺序错了导致 WA 了，吐了。就自己想错了一种 case，其实完全模仿 H 题即可。
