

## [2020 China Collegiate Programming Contest Changchun Onsite](https://codeforces.com/gym/102832)

### D：无意义的序列

首先 c = 0 时特判，$c \geq 1$ 时，观察到 $a_n = c^{bit}$, bit 为 n 的二进制中 1 的个数。然后我们只需看小于 10...0（k 个 0） 时的答案即可。

### F：dsu on tree

首先，我们可以枚举 `lca(i, j)`，也就是说每一个节点都可以当其子树的 lca，它的两个子树中元素的 lca 必然是它。因此把这个答案算成是这个节点的答案。然后就是轻重链的问题了。注意到这里答案是异或值求和，那么我们可以诸位考虑即可。这里的写法跟 600E 的写法不一致。其实也可以写成一致的样子，600E 也可以写成我这个样子。

### H：二分图博弈

### K：gcd once more

考虑 $\gcd(x, y) = x ^ y$。我总想把最终形式给搞出来（想太多，吃力不讨好），首先显然 $x \neq y$（不考虑 0），不妨设 $x > y$，那么 $x - y \geq \gcd(x - y, y) = \gcd(x, y) = x^y \geq x - y$。从而知道 $\gcd(x, y) = x^y = x - y$，然后我还一直想继续推，甚至猜想 $x = 2^k(2n + 1), y = 2^{k + 1} \cdot n$，浪费了特别多的时间，其实此时显然可以枚举 gcd 的值在 $O(n \log n)$ 把所有情况找出来嘛。后面就是并查集常规操作了。
