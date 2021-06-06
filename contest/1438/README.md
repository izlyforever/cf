## [Codeforces Round #682 (Div. 2)](https://codeforces.com/contest/1438)：数学场

### A

$a_i = 1$ 即可

### B

若存在 $i \neq j$ 使得 $a_i = a_j$，则 YES，否则 NO（考虑二进制）

### C

可以根据假设强制让 $a_{i + j}$ 与 $i + j$ 有相同的奇偶性，那么必然满足条件，此问题一般化 [解法](https://codeforces.com/contest/1438/submission/98431377)

### D

注意到首先我们可以让数列成对相等并且 $x \otimes x \otimes y = y$，所以如果 $n$ 为奇数，必然就 YES，若 $n$ 为偶数，我们成对这样搞之后，会有两个元素可能不等，又注意到它们相等当且仅当所有值异或为 0，所以搞定
> 代码索然无味就不写了