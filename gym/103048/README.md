
## [2021 ECNU Campus Invitational Contest](https://codeforces.com/gym/103048)

质量还是很不错的

### A：简单线性代数，写的是否 `f(a, b)` 写成 `f(a, d)`，然后一直出问题了

### B：知道怎么处理，但是写的话很麻烦

最后终于磨出来了，从尾部开始考虑，然后判断即可。题目中 n 可以变得更大。

### C: 送分题

### D: 阶乘的 p 因子指数

### E: 树上两点距离

### F: 得到线性关系，然后一个一元二次方程即可

### G: 分情况讨论一下

### H: 分治，但是我不会（原始题目：[COCI 2020](https://loj.ac/p/3370)）

[kczno1 的 AC 代码](https://loj.ac/s/1047075)

本来想自动向量化暴力做这个问题，后来发现还是不行。

### I：送分题，但是 [我的第一次提交](https://codeforces.com/gym/103048/submission/112910033) 有 bug 也过了（ba, aa) 应该是 NO

### J: 求 $\sum_{i = 1}^n \frac{1}{i}$

求上述结果时，若 $n$ 特别大，可以求  $\sum_{i = 1}^n \frac{1}{i} \simeq \sum_{i = 1}^N \frac{1}{i} + \ln n - \ln N$

### K: 仅有几个是可以的，特判一下即可

## [Educational Codeforces Round 107 (Rated for Div. 2)](https://codeforces.com/contest/1511)

### E：用概率是最好的理解

分别考虑一整行 o 和 一整列 o 的情况。

### F：如何求一个计算式（不懂）

### G：暴力黑科技能搞，但是标准做法是每一位考虑

每一位考虑的好处是有很多减了之后不影响答案。