# [Codeforces Round #791 (Div. 2)](https://codeforces.com/contest/1679)

## A

- $n$ 若为奇数，必然不行，所以不妨 $n$ 自除 2
- 如果 $n = 2$，显然不行，否则答案为 $n / 3 + !!(n \mod 3), n / 2$

## B

可以用 map 保存特殊的答案，然后用 一个 last 记录上次 2 操作的值，这样就可以 $O(n \log n)$ 解决

但是一个 $O(n)$ 做法，用一个 cnt 记录 2 操作的次数，然后对于特殊的值用另一个数组标记这个值被更新过了，具体见代码 `b1.cpp`


## C

又又又又看错了题，我以为是个二维树状数组，结果题意搞错了

这个题就是单点更新，然后区间最小值的线段树

但其实也可以用 set 记录哪些位置是空的，也是一样的道理，代码更简洁，见 `c1.cpp`

## D

想的太复杂了，为什么我想不到二分答案，然后拓扑排序呢！