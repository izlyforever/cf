# [Codeforces Round #729 (Div. 2)](https://codeforces.com/contest/1542)

## A

判断奇偶是否对半即可

## B

注意到最终任何元素都可以写成  $a^i + b j$ 的形式，其中 $i, j \geq 0$ 

## C

我们只要看对每一个 $x$, 满足 $f(i) = x$ 的数有多少个即可。

从小到大遍历 $x = 2, 3, \cdots$，若遍历到 $j$，那么剩下的数是 $\text{lcm}(2, 3, \cdots, j)$ 的倍数

