# [Codeforces Round #775 (Div. 2, based on Moscow Open Olympiad in Informatics)](https://codeforces.com/contest/1649/)

## A

找左右两边连续的 1 的位置

## B

这个最看最大 mx 的和总和 sm 的关系，注意全 0 的情况

## C

记录每个值的位置，然后横纵坐标分别算（排序，然后求类和计算即可）

## D

这题本来想用 整除分块来做的，结果发现 $c \sqrt{c}$ 的算法过不了，然后用各种歪门邪道的卡常优化。然后没办法另想一个 $c \log c$ 的做法过了

具体的说，如果 $i \in S$，且 $j \not \in S$ 但是 $[i \cdot j, (i + 1) \cdot j - 1] \cap S \neq \emptyset$（等价于 $sm[(i + 1) \cdot j - 1] > sm[i \cdot j - 1]$），那么必然不行。

## E

这题一眼就会，但是 D 搞了太久没时间了，好气啊！

首先预处理出 `fac, ifac`，然后用 ModInt 会更加方便，不用也行。注意到如果当前为小于 $t[i]$，那么后来任意次序都可以，否则当前为取 $t[i]$ 然后再搞一次。当前步骤时的答案

$$
\frac{(n - i)!}{c_1! \cdots c_m !} \sum_{j = 1}^{t[i] - 1} c_i
$$

所有用数状数组维护前缀和，然后维护一下分母的阶乘即可
