# [Codeforces Round #744 (Div. 3)](https://codeforces.com/contest/1579)

## C

枚举下顶点即可

## D

每次选两个权重最大的即可，用 `std::priority_queue<std::pair<int, int>>` 存一下即可

## E1

贪心只用比较第一位即可，用 `deque` 存

## E2

离散化，然后树状数组，看一下比当前数大和比当前数小的数谁少

## F

显然可以搞成好几个圈，然后每一个圈只用看最多连续 1 的个数，然后注意到是一个环，所以可以双倍快乐，再特判一下全 1 的情况


## G

本来没思路，后来一看 $n < 10^4$ 大概是个平方算法，然后突然发现一个数字在哪不重要，重要的是相对左右位置在哪。
然后注意到答案必然小于两倍的最大值，即小于 2000，所以我们可以用 `b[i]` 表示：相对左端点距离为 $i$ 时，相对右端点距离的最小值。然后 dp 就很明显了，每一步，要么向左要么向右
