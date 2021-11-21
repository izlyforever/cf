# [Codeforces Round #755 (Div. 2, based on Technocup 2022 Elimination Round 2)](https://codeforces.com/contest/1589)

## A

$u^ 2 - v^2 = (u + v)(u - v)$

## B

显然切成 $3 \times 1$ 或 $1 \times 3$ 最好

## C

排序比较即可

## D

我们可以找到最右端点，然后 3 次就可以了（2 次也可以，但是没必要）


## E

这是一道经典贪心问题，而且之间也见过，但是每次都不会？有点搞，这次必须搞定（其实沉下心来慢慢推导公式也是可以做出来的）

按照题解的说法：首先定义数组 $c$ 为 $c_i$ 表示移除 $1, \cdots, i - 1$ 后，第 $i$ 个位置石头个数。所以  $c_0 = 0$, $c_i = a_i - c_{i - 1}$。所以 $[1, r]$ 能赢当且仅当 $c_i \geq 0 \forall 1 \leq i \leq r, c_r = 0$。

现在我们分析做左端点为 $l$ 的情况，定义序列 $a^l = a_l, \cdots, a_n$, $a^l_i = a_{l + i - 1}$，同理我们可以对 $a^l$ 定义 $c^l$，从而 $[l, r]$ 能赢当且仅当 $c^l_i \geq 0, \forall l \leq i \leq r - l + 1, c^l_{r - l + 1} = 0$。而注意到

$$
c^l_i = a^l_i - a^l_{i - 1} + \cdots + (-1)^{i - 1} a^l_1 = a_{l + i - 1} - a_{l + i - 2} + \cdots + (-1)^{i - 1} a_l = c_{l + i - 1} + (-1)^{i - 1} c_{l - 1}
$$

因此 $c^l_i < 0$ 当且仅当 $c_{l + i - 1} < (-1)^i c_{l - 1}$，因此我们可以分奇偶，对每个 l 找到对应的 i。$c^l_i = 0$ 也是同理的，于是我们可以二分查找找到所有的合理的 $c^l_i = 0$ 的位置
