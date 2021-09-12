LeetCode 最大的好处就是每次错了会给你一组错的例子，坏处显而易见：没有自动补全

## [周赛 258](https://leetcode-cn.com/contest/weekly-contest-258/problems/smallest-missing-genetic-value-in-each-subtree/)

### [5869. 两个回文子序列长度的最大乘积](https://leetcode-cn.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/)

枚举所有的回文（注意记录的是下标），然后两两判断，更新结果

### [5870. 每棵子树内缺失的最小基因值](https://leetcode-cn.com/problems/smallest-missing-genetic-value-in-each-subtree/)

MEX 问题，注意到这里的基因值是两两互异的，因此只有树上一条链上的值非 1

如果去掉这个条件需要树上合并，就会有点搞，需要 dsu on tree，再处理重儿子的答案，再处理轻儿子的答案