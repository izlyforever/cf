# [Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)](https://codeforces.com/contest/1556)

## A

看奇偶，然后特判一下

## B

注意最终必然是奇偶交错的

## C

首先固定左端点 $i$，这么至少选择一个，至多选择 $a[i]$ 个，注意到整个过程中如果有括号更多直接结束，处理的时候，能简洁就不要绕(被折磨死)

## D

我们可以先看三个的情况，两两 and 且 or，然后就可以知道这三个的值了。这是因为 $a + b = (a | b) + (a & b)$
