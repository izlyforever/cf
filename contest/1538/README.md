## [Codeforces Round #725 (Div. 3)](https://codeforces.com/contest/1538)

### A：确定最大最小值位置即可

### B：大于平均值的重新分配

### C：排序后二分查找即可

### D：看素因子个数

### E

一开始大意了，直接暴力存储，炸了。然后发现只需保存前 3 个字符和后 3 个字符，以及当前答案即可。不足 3 个字符的时候要细心处理一下

### F：进位导致的符号改变

一般套路就是处理 $0 \to n$ 的情况，再相减即可

### G：二维线性规划

不妨设 $a \geq b$，若 $a = b$ 是明显的，其它情况解方程。不妨假设 $\gcd(a, b) = 1$，然后假设最终答案是 $t_1 + t_2 = c$，那么

$$
a t_1 + b t_2 \leq x, a t_2 + b t_1 \leq y
$$

可知 $t_1$ 要满足 $0 \leq t_1 \leq c$ 且 $ ac - y < (a - b) t_1 < x - b c$，然后显然 $c$ 可取范围是一个连续的区间，因此我们可以二分一下。
