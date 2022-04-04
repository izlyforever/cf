# [Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)](https://codeforces.com/contest/1654)

这一场题目还是很有意思的，但是我自己打的稀烂

## A

最大两个值的和

## B

从右往左看每个字符第一次出现的位置的最左的位置

## C

直接求和，然后按照和一直划分下去

注意 map 的 key 值必须是 `long long`，要用 map 而非 set


## D

首先所有节点构成一棵树，然后以 $0$ 号节点为根，开始 dfs，累加所有节点相对根节点的值，在记录相对根节点，每个素数的幂次至少为多少

## E

枚举公差 $d$，分两类

- $0 \leq |d| \leq \sqrt{N}$，对此直接暴力即可
- $\sqrt{N} < |d| < N$，对此能构成等差数列的相距不会超过 $\sqrt{N}$

然后我们可以通过平移的方式，避免使用 map
