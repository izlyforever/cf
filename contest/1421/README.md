## [Codeforces Round #676 (Div. 2)](https://codeforces.com/contest/1421/)


### A：异或，和，交的关系

> $(a \oplus x) + (x \oplus b)$ 的最小值，$a \oplus b$，此时 `x = a & b`

### E：观察总结题（加减号问题）

- 任何情况下的答案都是 每一项前添加正负号得到的。
- 相邻两个之间添加的正负号必然有一个是相同的，即不会出现 `+-+-+` 或 `-+-+-` 的情况
- 负号个数 $m$，总个数 $n$，满足 $(n + m) \equiv 1 \mod 3$（可以通过归纳得到，并且 $n$ 个正负号的情况可以看作 $n - 1$ 个正负号中某一个改变符号并且出现两个，再塞进去）
- 所有的情况如上所言（可以数学归纳证明）

我们用 `DP[n][3][2][2]` 保存全部状态。`DP[i][j][k][p]` 分别表示当前 `i` 个位置，(i + 负数个数 `mod 3`) 等于 `j` 且`k` 表示是否非法（是否存在连续的正或负），`p` 表示最后以为是否为正的最大结果。

> 例如 `DP[i][j][1][1]` 表示前 `i` 位（`i` 与 前 `i` 位负号个数的和模 3 位 `j`) 且有连续的负号或者正号，且第 `i` 位为负号的最大和。

> 此题多维数组写 Vector 不方便，但是又不能开局部数组（因为太大了），所以只能全局变量啦。
