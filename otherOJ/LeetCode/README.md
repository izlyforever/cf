LeetCode 最大的好处就是每次错了会给你一组错的例子，坏处显而易见：没有自动补全


## [LCP 49. 环形闯关游戏](https://leetcode-cn.com/problems/K8GULz/)

可以从高位到低位一位一位的试，如果不要这一位，且这一位后面所有值都填 1，如果可以解决，那这位不必要，否则就必然需要。

然后每次试可以做到 $O(n)$

- 将原数列 双倍快乐 就可以破环为线上问题了
- 用一个 `std::pair<int, LL>` 的 pair 数列 left，从 i 出发往两边走，走过的地方就标记已经走过了，然后用 left[最右边] = {最左边，或和}，然后 i 从小到大跑（到 n 结束），走过的直接跳过，拓展的时候可以借助之前的 left 跳步，然后如果最右可达到 2n 那么就 ok

> 上面表达可以会有开闭的问题，具体见代码细节


从而总体能达到 O(n \cdot Bit)

## [周赛 259](https://leetcode-cn.com/contest/weekly-contest-259)

### [5877. 检测正方形](https://leetcode-cn.com/contest/weekly-contest-259/problems/detect-squares/)

map 存点，搞对角就行了，但是！！！我以为题目要考虑矩形，结果看了半天硬是没看出来错在哪

### [5878. 重复 K 次的最长子序列](https://leetcode-cn.com/contest/weekly-contest-259/problems/longest-subsequence-repeated-k-times/)

首先统计出所有可能的字符（算重），然后主题字符总数不超过 7（算重），然后暴力，总共要考虑的字符串不会超过
$$ 
7! + 7 \cdot 6! + {7 \choose 2} 5! + \cdots < 10^4
$$
然后还能剪枝优化一下，然后每个字符串最多处理 $n(n < 16000)$ 次，所以肯定不会超

## [周赛 258](https://leetcode-cn.com/contest/weekly-contest-258/problems/smallest-missing-genetic-value-in-each-subtree/)

### [5869. 两个回文子序列长度的最大乘积](https://leetcode-cn.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/)

枚举所有的回文（注意记录的是下标），然后两两判断，更新结果

### [5870. 每棵子树内缺失的最小基因值](https://leetcode-cn.com/problems/smallest-missing-genetic-value-in-each-subtree/)

MEX 问题，注意到这里的基因值是两两互异的，因此只有树上一条链上的值非 1

如果去掉这个条件需要树上合并，就会有点搞，需要 dsu on tree，再处理重儿子的答案，再处理轻儿子的答案