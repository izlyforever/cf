# [Codeforces Round #763 (Div. 2)](https://codeforces.com/contest/1623)

## A

横纵坐标分别考虑，然后取最小值即可

## B

对于 $[l, r]$，我们对每个右坐标（用 set）保存它的左坐标。然后对每个区间分别求值即可。

- 如果当前 $left[r]$ 仅有一个元素，那么显然此时删除的即可 $r$
- 否则删除的就是最小的那个减 1

## C

显然我们可以对答案二分，然后从后往前贪心，注意每个位置给前面的个数不能超过它原来的 $\frac{1}{3}$

## D

这个题注意到 $x$ 坐标每 $2(n - 1)$， $y$ 坐标每 $2(m - 1)$ 就回到原来的状态，所以经过 $T = 2 \text{\lcm}(n - 1, m - 1)$ 就回到原始的位置。所以最终答案

$$
E = \sum_{i = 0}^{T - 1} i \cdot p_i  + \hat{p} (E + T)
$$

移项即可求解，至于 $p_i$ 可以模拟机器人的位置得出，$\hat{p}$ 同理

## E

待补
