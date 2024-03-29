## [Harbin Engineering University Collegiate Programming Contest 2021](https://codeforces.com/gym/103061)

### A：用 Set 对区间进行贪心筛选，然后贪心查询即可

### B：签到水题

### C：贪心，从左到右，打标记，用下 Set 即可

### D：双指针，树状数组或线段树区间加

> 这里同样可以用树状数组的思路优化成 $O(n)$

### E：简单递推博弈

这个设此次取值为 x，后面先手期望为 f，然后列式子发现此次先手的期望为 $|x - f|$，然后从后往前递推即可

### F：简单二分

### G：很有意思的一道题

首先注意到（根出发）最短的那条路径必然全部要染色，然后我们可以设 $(d, u)$ 表示以 u 为根，每条路染色为 d 的方案数，注意到如果 u 不分叉（根节点特判一下），那么我们可以一直跑直到它分叉或者到叶子节点。如果 $d = dep[u]$，那么 u 必然要被染色，否则若分叉必然不被染色，若不分叉可能会被染色，这取决于最后能跑到哪里。

### H：相当的毒瘤，要特别细心

首先把它变成 $1, -1$ 交替出现的形式，然后再看 $-1$ 的个数的奇偶性

> 特别注意，$-1, -1, -1, 1$ 要变成 $-1, 1, 1$ 而非 $1, -1, 1$

### I：签到题

### J：有意思的简单 DP 题

> 注意对称性

### K：数论题

首先这个期望与每个排列的圈的个数有关。长度为 $n$ 的排列的圈的期望为 $a_n$，那么我们显然有

$$
a_n = \frac{1}{n} (a_{n - 1} + 1) + \frac{n - 1}{n} a_{n - 1} = a_{n - 1} + \frac{1}{n}
$$

> 这个转移是注意到：点是退化的链，且一旦形成了圈就不再变了

然后用并查集维护一下即可。

### N：签到题
