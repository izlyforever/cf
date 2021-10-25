# [2021 ICPC Gran Premio de Mexico 1ra Fecha](https://codeforces.com/gym/103274)

## G

这不是 SG 问题，只是简单的逻辑推导问题，只考虑 $0, 1$ 的情况，因此只需看前 $m$ 个值中有无 0 即可，所以只需记录最后一个 0 的位置即可。然后用 `__builtin_popcount` 即可，但是其实用 `BitCount5` 更快，当然直接使用 `__builtin_parity` 最快

如果多组，用 SG 的办法，那岂不是必然需要一个 map 吗？那怎么做到 $o(n)$ 呢，貌似最多可以做到 $O(n \log m)$

使用一个 RingBuffer 和一个 map，存一个固定的答案，注意到 sg 的值不会超过 $m + 1$.

重新把此问题修改成：石子 $n_1, n_2, \cdots, n_k$(\sum n_i \leq N)，每一个 $n_i$ 的二进制中 1 的个数都是偶数。每次可以从某一堆 i 中取 $x_i$ 个，$1 \leq x_i \leq m_i$，$1 \leq m_i \leq M$，取完之后需要保证剩下的石子的二进制中 1 的个数为偶数，无法取的人输。这就变成了另一个经典的 SG 问题，写在博客里吧
