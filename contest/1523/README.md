## [Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)](https://codeforces.com/contest/1523)

A 题题目理解错误被卡了一下，怕掉分就没敢做，其实只要做出 D 就可以加分，我当时不自信

### A：注意到最多 n 次就开始稳定了

### B：只考虑两个的情况就可以了

### C：直接从头开始，然后找可能即可

> 我一开始以为要从后面开始找，浪费了点时间

### D：一看这题就要用 mask，但是没想到是概率 + mask

看 [jiangly](https://codeforces.com/contest/1523/submission/117890786) 代码还学了一手卡时间技巧

这个 mak 的处理特别细节 $p \cdots 2^p$，值得学习，当然也可以直接暴力 $3^p$。

### E：组合概率问题

有连续 n 个灯，如果一个长度为 k 的区间包含大于两个亮的灯就停止工作，问停止工作时亮灯的个数的期望

所以假设现在有 p 个亮灯但是没有停止工作，这等价于

$$
a_0 + \cdots + a_p = n, a_0 \geq 0, a_1, \cdots, a_{p - 1} \geq k, a_p \geq 1
$$

所以种类是 $\binom{n - (p - 1)(k - 1)}{p}$

[虽然这不是最终停止工作时的答案，但是它贡献了答案](https://codeforces.com/blog/entry/91271?#comment-798021)。
