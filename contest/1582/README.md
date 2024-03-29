# [Codeforces Round #750 (Div. 2)](https://codeforces.com/contest/1582)

## A

如果此题不要求 $a, b, c$ 大于 0，会相对较为复杂，要考虑 3 个 2，2 个 3 的情况

## B

显然为 $cnt[0] \cdot 2^{cnt[1]}$

## C

对每一个字符 x，判断最少删除多少个点成为回文

## D

若 $n$ 为偶数，那么两两配对即可，否则有一组为 3 个数的，然后必然有两个只和不为 0，然后把这两个看作一个点即可

## E

DP，从后往前，看每一个位置是否可以作为最后一个位置来处理，然后注意到 `std::vector` 的 clear 是不会真的清掉内存的，所以需要加上 shrink_to_fit 来清掉内存

## F1

注意到答案不会超过 512，然后直接 DP 即可，复杂度 $512 n$

## F2

此时答案不会超过 8192，但是此时直接 DP 就不太行，要记录下每个 N 对应的位置，然后记录下要 left[i] 表示取得答案 $i$ 的最早位置
