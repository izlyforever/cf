# [Codeforces Round #761 (Div. 2)](https://codeforces.com/contest/1617/)

## A

没思路（理解错题意，没注意题目说 $S'$ 是 $S$ 的一个置换，以为是子序列）

所以如果 $T=abc$ 就把 $bc$ 位置互换一下（在有 $a$ 的前提下）

## B

我竟然一开始想找规律，还找错了吐了。注意到，对于  $n > 6$ 我们总能找到 $a, b > 1$ 满足 $a + b = n$ 且 $\gcd(a, b) = 1$。找的方法就是找一个素数 $p$ 使得 $p \not | n$

## C

这个题就贪心一下即可，然后注意到有些情况如果在 $1 \to n$ 之间有数，就尽量用，然后再依次配对。注意一定要用 multiset，而非 set

> 由此多了三次提交

## D

首先包容排斥原理，依次遍历（每组 3个），至少有一组返回 1， 至少有一组返回 0。
然后把这两组数字挨着，然后依次平移处理，必然有从 1 到 0 的哪一步，这样就知道了左边的那个为好人(crewmates)，右边的那个坏人(impostors)。然后用这两个附带一个去做 query。然后注意到对于好的组和不好的组分别在右边放 1 或者 0，这样每组最多再加 2 次

综上最终最少需要 n + 2 才能确保得到正确答案

> 误以为要计算好人数，WA 后看了半天没看出来，吐了
