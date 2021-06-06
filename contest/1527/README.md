
## [Codeforces Round #721 (Div. 2)](https://codeforces.com/contest/1527)

### A

求最大的 $k$ 使得 $n \And (n−1) \And (n−2) \And ... \And k = 0$，显然二进制 n 为 $1...$，不把首个 1 消了不可能为 0，所以答案就是 `1 << std::__lg(n) - 1`

> 因为 cf test 太卡导致 cf submit 时 00::02:01 气死了。我去改 cf-tool 设置！

### B

B1 比较简单，一开始就是回文，此时如果 n 为偶数，后手必胜；若 n 为奇数，此时中心元素若是 1，那么就跟 n 为偶数没区别；否则中心元为 0, 那么先手必抢这一点，那么如果还有多余的 0，那么先手必赢，否则必输。

B2 如果一开始不是回文，那么先手想怎样就怎么样，等到只有一个地方不是回文的时候果断把那个位置一填，就基本赢了，唯一的可能和就是 n 为奇数中心元为 0，且只有两个 0

### C

真的气，我以为是求逆序数，交了一把逆序数上去，吐了。后来发现是看相等的地方，那么直接 map 一下考虑贡献即可。

### D

首先注意到 $Mex(S) > i$ 当且仅当 $S$ 中存在 $0, 1, 2, \cdots, i$。

> 不包含 $i$ 可以推出 $Mex(S) \leq i$ 但这不是充要的。

那么我们找路径中包含它们的值即可。因此我们可以让树的每个节点记录它的子孙中节点编号的最小值（并且把这个分支当作真儿子），且记录以它为子树的大小。

$Mex(S) = 0$ 当且仅当 $S$ 中不包含 $0$，那么就是 0 为根的树，每一个分支中任取两点再求和即可
$Mex(S) > 0$ 当且仅当去掉 $Mex(S) = 0$ 的情况
$Mex(S) > 1$ 当且仅当包含 1，那么答案就是 $sz[1] \cdot (n - sz[son[0]])$ 而非 $sz[1] \cdot (n - sz[1])$！因为 0 和 1 不一定直连啊！哎。
如果 i + 1 在 i 的子树中，那么就一直往下跑，答案为 $sz[i + 1] \cdot (n - sz[son[0])$，否则我们还有一次机会，这个时候 $i + 1$ 在另外一个分支上，在哪无所谓，答案变成了 $sz[i + 1] \cdot sz[i_0]$。再往下跑，不满足条件就结束。

最后 $|Mex(S) = i| = |Mex(S) > i - 1| - |Mex(S) > i|$

> 特别的生气！！！ 我为什么弱智的把 $sz[1]$ 和 $sz[son[0]]$ 搞混淆了！！！ 啊，好气啊！就差这么一点，这个题做出来直接能 +100 多，就能打破我的最佳排名记录了。后来我发现我想错的点不止一个，确实是自己实力不够。