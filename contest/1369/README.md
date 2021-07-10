## [Codeforces Round #652 (Div. 2)](https://codeforces.com/contest/1369)

### D:  组合计数问题

> 题解写在官方的 [教程里面](https://codeforces.com/blog/entry/79235#comment-648996)，代码也不想 copy 过来了。

补充一个更好的生成函数的做法：已知 $a_n$，满足 $a_n = a_{n-1} + 2 a_{n-2} + (n \% 3==0?4:0)$，$a_0 = a_1= a_2 = 0$，计算$a_n$。

设 $f(x) = \sum_{n=0} ^ {\infty} a_n x^n$，则我们有
$$
f(x) = \sum_{n=0} ^ {\infty} (a_{n-1} + 2 a_{n-2} ) x^n + \sum_{n=1} ^ {\infty} 4x^{3n} = xf(x) + x^2f(x) + 4 \sum_{n=1} ^ {\infty} x^{3n}
$$
所以
$$
f(x) = \frac{4 \sum_{n=1} ^ {\infty} x^{3n}}{(1-2x)(1+x)}
$$
由于 $\frac{1}{1-x} = \sum_{n=0}^{\infty} x^n$，所以 $\frac{1}{(1-2x)(1+x)} = \frac{2}{3(1-2x)} + \frac{1}{3(1+x)} = \sum_{n=0}^{\infty} \frac{2^{n+1}+(-1)^n}{3}x^n$（推荐），$\frac{1}{(1-2x)(1+x)} = \sum_{n=0}^{\infty} (2x)^n \sum_{n=0}^{\infty}(-x)^n = \sum_{n=0}^{\infty} \frac{2^{n+1}+(-1)^n}{3}x^n$（不推荐），因此
$$
f(x) = \frac{4}{3} \sum_{n=0} ^ \infty (\frac{2^{n \% 3 +1} (8^{n/3}-1)}{8-1} + \frac{(-1)^{n \% 3 +1} ((-1)^{n/3}-1)}{-1-1}) x^n
$$


### F：博弈题

> 给定两个正整数 $s \leq t$，$A,B$ 两人依次玩游戏，每次可以从$s$变成 $s+1$ 或 $2s$，谁先严格大于 $t$，谁输了。
>
> 现在给你一堆的 $s_i,t_i$，$A,B$ 两人依次玩游戏，每一局输了的人作为下一局开始的人。问 $A$ 能否最后一局必赢，能否最后一局必输

先考虑单个 $s,t$ 的情况。

用$f(s,t)$ 分别表示$A$ 是否有必胜策略。

- $t$ 为奇数，若 $s$ 为偶数，那么 $A$ 就让它变成 $s+1$，那么无论 $B$ 如何操作只能变成偶数，所以此时 $f(s,t) = 1$，若 $s$ 为奇数，显然若 $B$ 用 $A$ 刚刚的策略，则 $A$ 输，$f(s,t) = 0$。
- $t$ 为偶数，若 $2s>t$，此时只能做加法，$f(s,t) = s \mod 2$，若 $4s>t \geq 2s$，此时 $f(s,t)=1$ ，因为总可以变成 $f(2s,t)=0$。若 $4s \leq t$，若 $f(s,\lfloor \frac{t}{4} \rfloor) = 1$, 则 $A$ 必有策略到达区间 $(\lfloor \frac{t}{4} \rfloor,2\lfloor \frac{t}{4} \rfloor)$ 的某一点，从而 $f(s,t)=1$, 同理若 $f(s,\lfloor \frac{t}{4} \rfloor) = 0$，则 $B$ 有 $A$ 的策略，从而 $f(s,t)=0$ （**比赛的时候能想出来的人是真的虎**) 。

用 $g(s,t)$ 分别表示 $A$ 是否有必输的策略：若 $2s>t$，则 $g(s,t)=1$，同理，若 $2s \leq t$，$f(s,\lfloor \frac{t}{2} \rfloor)=1$，则必有策略使得 $B$ 到达 $(\lfloor \frac{t}{2} \rfloor,2\lfloor \frac{t}{2} \rfloor)$ 的某一点，所以 $g(s,t) = f(s,\lfloor \frac{t}{2} \rfloor)$

有了这两个函数后，我们就可以从后往前依次来决定最后能否有必胜或必输的决策。

> 我们可以认为一开始仅有必输策略所以让$A$先选，然后如果$A$原来有必胜且有必败策略，这后面必然一直有，若没有必胜也没有必败策略，则后面也是。所以只用考虑仅有其中之一的情形。
