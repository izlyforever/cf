## [Contest 2050 and Codeforces Round #718 (Div. 1 + Div. 2)](https://codeforces.com/contest/1517): 质量高代码实现能力要求极高

### B

$i, j$ 写反，debug 了 15 分钟，真的烦！导致后面用时都加了

### C

超级有趣感觉，找找规律就会发现往下一跳对角线，规模就变小了，然后跑 n 次好了

### D

标准 DP 没啥好说的

### E

推理一下 10 分钟，就知道怎么做，但是这个代码实现是真的把自己给整吐了，这个时候就要参考一下 [dreamoon_love_AA](https://codeforces.com/contest/1517/submission/114026617) 的做法了。
用全局变量加数组，然后 i 从 1 开始，这样会让很多东西简单不少（但是我还是不想写）。
