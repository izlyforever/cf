## [Codeforces Global Round 1](https://codeforces.com/contest/1110)

### D：打麻将 0.0

> 就是计算最容易听牌的数量，ABC 和 AAA 的个数和

考虑 `ans[n][i][j]` 表示只考虑小于 `n` 的情况下，有 `i` 个 `(n-1,n)`和 `j` 个 `n` 剩余的答案。由于三个 `(n,n+1,n+2)` 可以转化成 `(n,n,n),(n+1,n+1,n+1),(n+2,n+2,n+2)`，所以 `i,j` 都小于 3。且 `ans[n+1][j][k] = max(ans[n][i][j]+i+(c[n+1]-i-j-k)/3)`，最后可以优化一下空间。
