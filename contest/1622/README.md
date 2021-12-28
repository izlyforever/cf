# [Educational Codeforces Round 120 (Rated for Div. 2)](https://codeforces.com/contest/1622)

## A

分三种情况即可（不妨假设 $l_1 \leq l_2 \leq l_3$

- $l_1 + l_2 = l_3$
- $l_1 = l_2$
- $l_2 = l_3$

## B

用 map 排序，小的跟小的对应必然是一种最优策略

## C

假设最大的 $i$ 个最终跟最小的一致，看最终最小的至少要减少多少即可

## D

一开始直接去读 E 题去了，浪费了不少时间。自然是两边尽量为 0（最宽），然后就是 $\binom{r - l}{k}$，但是要注意重叠的位置，所以两个中间夹着的要去掉

## E

注意到 $\sum_{i = 1}^n |x_i - r_i|$ 总共有 $2^n$ 种可能，然后求最值就简单了。只需看权重，然后再排序计算即可
然后复杂度自然就是 $2^n \cdot n  m \log m$

## F

注意到最终答案不小于 $n - 3$。记 $f(n) \equiv \prod_{i = 1}^n i!$，且定义等价关系 $a, b > 0, a \equiv b$ 当且仅当 $\exists x, y > 0, \text{ s.t. }a x^2 = b y^2$。分情况讨论

- $n = 4k$，则 $f(n) \equiv (2k)!$
- $n = 4k + 1$，则 $f(n) \equiv (2k)! \cdot (4k + 1)!$
- $n = 4k + 2$, 则 $f(n) \equiv 2 \cdot (2k + 1)!$
- $n = 4k + 3$，则 $f(n) \equiv 2 \cdot (2k + 1)! \cdot (4k + 3)!$

但是注意到，有些情况下，后面的部分依然能化简，但是数字又太大咋办呢？一个想法就是用 hash，但是必须要满足 $hash[i] = hash[i * j^2]$

看 [generic_placeholder_name](https://codeforces.com/profile/generic_placeholder_name) 的 [代码](https://codeforces.com/contest/1622/submission/140873302)

``` cpp
for(int i = 2; i * i < N; i++) if(f[i] == 0) {
  for(int j = i * i; j < N; j += i) if(f[j] == 0) f[j] = i;
}
for(int i = 2; i < N; i++) {
  if(f[i] == 0) {
    hsh[i] = rng();
    f[i] = i;
  }
  else {
    hsh[i] = hsh[f[i]] ^ hsh[i / f[i]];
  }
}
```
