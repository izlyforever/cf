## [Educational Codeforces Round 90 (Rated for Div. 2)](https://codeforces.com/contest/1373)

### E：$f(x)$ 表示非负整数 $x$ 的十进制表示的各位数之和。求最小的非负整数 $x$ 使得 $\sum_{i=0} ^k f(x+i) = n$

由于 $0 \leq k \leq 9$，也就是说 $x,x+1,\cdots,x+k$，的个位数各不相同。我们可以枚举 $x$ 的个位数，那么 $x/10,\cdots, (x+k)/10$，最多仅有两种取值。若只有一种，即没有进位（不能为 9），那么直接就可以把 $x$ 的位数和求出来，否则 $x/10$ 的个数必为 9。