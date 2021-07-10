## [Codeforces Round #597 (Div. 2)](https://codeforces.com/contest/1245)

### F：经典 XOR 递归

> 在区间 `[l,r)` 中找 `(a,b)` 使得 $a+b = a \wedge b$ 的个数 $f(l,r)$。

显然，$f(x,x) = 0 \; (x\neq 0),\; f(2l,2r) = 3f(l,r)$，若 $l$ 为奇数，那么 $f(l,r) = f(l+1,r) + 2(g(l,r)-g(l,l))-(l==0)$，若 $r$ 为奇数，那么 $f(l,r) = f(l,r-1) + 2(g(r-1,r)-g(r-1,l))-(r==1)$ 。其中 $g(x,n)$ 表示满足下式的 $y$ 的个数：
$$
0 \leq y < n ,\; x+y = x \wedge y
$$
通过比较 $x,n$ 的二进制，$g(x,n)$ 的计算是容易计算的的。