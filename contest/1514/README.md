
## [Codeforces Round #716 (Div. 2)](https://codeforces.com/contest/1514)

[mohammedehab2002](https://codeforces.com/profile/mohammedehab2002) 的连续第一场

### C: 拓展 Wilson 定理

即使不用这个定理也行。原理: 首先不能放与 $n$ 不互素的元素，否则乘积必然不与 $n$ 互素，从而不可能为 $1$，把剩下的数乘起来，如果为 $1$ 就好了，不为 $1$，必然是其中一个，把那一个踢了就行。

拓展 Wilson 定理：
$$
\prod_{1 \leq k \leq n, \gcd(n, k) = 1} k = \left\{ \begin{array}{rl} 
-1 & n = 2, 4, p^a, 2 p^a, p > 2 \text{ is prime}\\ 
1 & \text{else}
\end{array}\right.
$$

即 n 为原根时为 -1， 其它情况为 1.

> 我们判断的使用用 $= n - 1$ 来判断结果 $n = 2$ 的时候给了我一次 WA


### D：概率做法真的骚气

区间有超过一半的元素就才会计数，因此，我们可以概率枚举 50 次。当然了常规做法是主席树（不会）会计数的众数必然是中位数。也可以用莫队。
