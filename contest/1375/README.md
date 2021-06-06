## [Educational Codeforces Round 75 (Rated for Div. 2)](https://codeforces.com/contest/1251)

### D: MEX once more，通过修改数组的某一个值成 mex，使得数组最终非降

> 不妨最终变成 `0~n-1`，这是不好想的，特别是紧张的比赛的时候

如果当前`mex = n` 即数列正好是一个排列，此时选择任意一个`a[i]!=i` 的位置，让 `a[i]=n`，否则 `mex < n` 此时令`a[mex]=n`

