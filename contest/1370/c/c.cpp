#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	while(cas--){
		int n;
		cin>>n;
		auto f = [](int n){
			if(n == 1) return false;
			if(n%2 == 1||n == 2) return true;
			int nn = (n&-n);
			if(n == nn) return false;
			if(nn>2) return true;
			n/=2;
			for(int i=3;i*i<=n;++i){
				if(n%i == 0) return true;
			}
			return false;
		};
		cout<<(f(n)?"Ashishgup":"FastestFinger")<<endl;
	}
	return 0;
}