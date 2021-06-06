## [Codeforces Round #651 (Div. 2)](https://codeforces.com/contest/1370)

### D：在长为 n 的序列中找一个长为 k 的子列，子列中奇数项最大值和偶数项最大值的最小值最小

> 比赛的时候，我很快就知可以二分查找答案，但是顾前不顾尾，下面代码没过，因为当最后一个数正好是满足 `a[i]<=m` 时答案就不行了！__应该按照原来的逻辑去叠加啊！__

``` C++
// 此代码是错误代码！
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	int a[n],r=0,l=1e9+2;
	for(int i=0;i<n;++i){
		cin>>a[i];
		r = max(r,a[i]);
		l = min(l,a[i]);
	}
	auto f = [&](int m){
		int now = -2,s=0;
		for(int i=k%2;i<n;++i){
			if(a[i]<=m){
				if(i>now+1){
					++s;
					now = i;
				}
			}
		}
		return s>=k/2;
	};
	while(l<=r){
		int m = (l+r)/2;
		if(f(m)) r=m-1;
		else l=m+1;
	}
	cout<<l<<endl;
	return 0;
}
```

### E：找出最少的轮换使得字符串 s 变成 t

我一开始知道是贪心，然后我以为 __是找到其中最长的连续 0 或者 1__，然后发现并不是！！！


``` C++
// 此代码是错误代码！
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n;
	string a,b;
	cin>>n>>a>>b;
	int ab=0;
	for(auto &x:a) if(x=='1') ++ab;
	for(auto &x:b) if(x=='1') --ab;
	if(ab){
		cout<<-1<<endl;return 0;
	}
	string s;
	for(int i=0;i<n;++i){
		if(a[i]!=b[i]) s.push_back(a[i]);
	}
	s+=s;
	//cout<<s<<endl;
	int ans = 0;
	for(int i=0,t;i<s.size();++i){
		if((i == 0)||(s[i]!=s[i-1])) t=0;
		ans = max(ans,++t);
	}
	cout<<ans<<endl;
	return 0;
}
```

然后看了[官方题解](https://codeforces.com/blog/entry/79107)！

在有解的前提下，我们可以构造取值在 $\{-1,0,1\}$ 的数组 $a$： if  $s_i = t_i,a_i = 0$，else if $s_i = 1,a_i=1$ else $a_i=-1$。因此答案就是
$$
\max _{1 \leq l \leq r \leq n} |\sum_{i=l} ^r  a_i| = max(\max _{1 \leq l \leq r \leq n} \sum_{i=l} ^r  a_i,\max _{1 \leq l \leq r \leq n} \sum_{i=l} ^r  -a_i)
$$