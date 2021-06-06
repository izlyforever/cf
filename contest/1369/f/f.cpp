#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	//freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	function<bool(LL,LL)> f = [&](LL s,LL t)->bool{
		if(t%2==1) return s%2==0;
		if(2*s>t) return s%2==1;
		if(4*s>t) return 1;
		return f(s,t/4);
	};
	function<bool(LL,LL)> g = [&](LL s,LL t)->bool{
		if(2*s>t) return true;
		return f(s,t/2);
	};
	int n;
	cin>>n;
	bool win=0,lose=1;
	for(int i=0;i<n;++i){
		LL s,t;
		cin>>s>>t;
		if(win^lose==0) continue;
		if(lose){
			win = f(s,t);
			lose = g(s,t);
		}else{
			win = !f(s,t);
			lose = !g(s,t);
		}
	}
	cout<<win<<" "<<lose<<endl;
	return 0;
}