# [Codeforces Global Round 18](https://codeforces.com/contest/1615)

## A

只用看和能否被整除即可

## B

可以单独考虑每一个位，然后考虑统计 $f([l, r]) = f([0, r]) - f([0, l - 1])$。可以选择打表，但是没必要

## C

首先假设有 $x(x > 0)$ 个 `1`, $n - x$ 个 `0`，那么下一步就有 $n - x + 1$ 个 `1`，$x - 1$ 个 `0`，再下一次（个数）就回到从前，相当于互换两个数的位置。

> 注意可能有两个都满足的情况

## D

注意到 $popcount(x \oplus y) \equiv popcount(x) \oplus popcount(x) \mod 2$，即
$parity(x \oplus y) = parity(x) \oplus parity(y)$，再令 $r_a$ 表示节点 $a$ 到根的路径上的异或值，然后 $(a, b, c)$ 即可表示成 $r_a \oplus r_b = parity(c)$，其中 $r_{root} = 0$，问是否存在这样一组解

## E

注意到 $w(r - b) = (n - r - b)(r - b) = b^2 - bn - r^2 + rn$。对于 red 来说，假设它选了 $r(r \leq k)$ 个，它必然想让 $b$ 的可选范围降低（不管 $r$ 的值为多少），那么做法自然是“污染”尽可能多的点：每次选深度最大的（选完了之后其它的深度都会改变），所以不好处理（但是其实不然，根据深度排序，之后再根据选择进行染色，然后跑完之后最终的深度就是真实的值），然后选择即可
