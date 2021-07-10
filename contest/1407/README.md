## [Codeforces Round #669 (Div. 2)](https://codeforces.com/contest/1406/)


### B：GCD 问题

> 如果数据范围特别大，则需要下面的处理方式，否则其实可以预处理 gcd 
> 如果这题 $c_i = \gcd(b_i, b_{i + 1}$ 将会超级难！

### C：第一次过真实的交互问题

注意到 $(a \mod b )> (b \mod a)$ 当且仅当 $a < b$ （这里 $a, b$ 都是正整数），并且此时 $(a \mod b) = a$

### D：经典问题：单调栈优化 DP