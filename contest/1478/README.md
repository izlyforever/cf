## [Codeforces Round #698 (Div. 2)](https://codeforces.com/contest/1478)

### D：GCD once more

此题，一眼看出系数之和恒定为 1，但是我一直想根据 k 的奇偶性递推，但是复杂度完全无法预测，一直卡着自己被卡炸了！
通过 `2x - y` 这样一直搞，那么最终只要满足 系数之和为 1，都会出现。所以这就是个 gcd 问题啊
$$
a_1 x_1 + \cdots a_n x_n = k, x_1 + \cdots x_n = 1
$$
有整数解，当且仅当
$$
(a_1 - a_i) x_1 + \cdots (a_n - a_i) x_n = k - a_i
$$
有解。当且仅当 $\gcd(a_1 - a_i, \cdots, a_n - a_i) | k - a_i$

我们可以取 $a_i$ 为最小值，这样求 gcd 就不会出现负数了。代码太简单就不写了。
