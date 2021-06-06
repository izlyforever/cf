#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const LL inf = 1e17+2;
int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	auto csum = [](int a,int b){
		return (a+b)*(b-a+1)/2;
	};
	auto f = [](int n){
		LL r = 0,d = 1;
		while(n>9){
			r+=9*d;
			d*=10;
			n-=9;
		}
		return r+n*d;
	};
	auto g = [&](int a,int k,int n) -> LL{
		LL r = 0,d = 1;
		if(n<a) return inf;
		while((n-a)%k){
			n-=9*(k-a);
			r+=d*9;
			d*=10;
			if(n<a) return inf;
		}
		return r+d*(f((n-a)/k+1)-1);
	};
	int cas;
	cin>>cas;
	while(cas--){
		int n,k;
		cin>>n>>k;
		if(k==0){
			cout<<f(n)<<endl;
			continue;
		}
		if(k*(k-1)/2 > n){
			cout<<-1<<endl;
			continue;
		}
		LL r = inf;
		for(int i=0;i<=9;++i){
			if(i+k<=9){
				int t = csum(i,i+k);
				if(n>=t&&(n-t)%(k+1)==0) r = min(r,10*f((n-t)/(k+1))+i);
			}else{
				int t = csum(i,9)+csum(0,i+k-10);
				if(n>=t) r = min(r,10*g(i+k-9,k+1,n-t)+i);
			}
		}
		cout<<(r==inf? -1:r)<<endl;
	}
	return 0;
}
