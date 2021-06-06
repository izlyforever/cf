## [Codeforces Round #694 (Div. 2)](https://codeforces.com/contest/1471)

### D：GCD 问题

题意：我们称 $a, b$ 相邻，如果 $\lcm(a, b)/gcd(a, b)$ 是平方数，这当且仅当 $ab$ 是平方数。我们定义 $f(n)$ 为 $n$ 的素因子的积，那么 $a, b$ 相邻，当且仅当 $f(a) = f(b)$。这样就好了呀。由于数据范围在 $1e6$ 之间，所以可以预处理以下就可以了。

> 上面做法还是太慢了！注意到 $f(n)$ 表示 $n$ 的最小 “无平方因子” 的因子。因此可以用平方数预处理，可用下面代码加速

``` C++
void init() {
	for (int i = 1; i * i < N; ++i) {
		int ii = i * i, cur = 0;
		for (int j = ii; j < N; j += ii) f[j] = ++cur;
	}
}
```

### F：图论染色问题

> 比赛时，读题没读懂要干嘛。

用 01 对连通图染色，使得每个 0 周围全是 1，每个 1 周围都存在一个 0. 按照题解的说法：随便选择一点置 0，然后把它周围全部染色为 1，然后找和 1 相邻的没被染色的其中任意一个染色为 0，然后把 0 周围全部染色为 1，一直继续下去。

但是上述做法代码可能写的比较别扭，因此我们可以用队列，先随便选择一点置 0，放进队列中。在队列中的被染色为 1 的是真 1，染色为 0 的表示它和某个染色为 1 的节点相连。出队���后染色为 1 的是真的 1。队首的被染色为 0，那就把和它相邻的没被染色的变成 1 放在队列中，队首的被染色为 1，那就把它相邻的全变成 0（不管有没有被染色过），若没被染色就丢进队列中。

注意到：被染色为 0 后，染色不会变化。出队列的 1 周围的染色全为 0，被染色为 0，必然是某个出了队列的 1 帮它染的