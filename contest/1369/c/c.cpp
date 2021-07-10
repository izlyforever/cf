#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin)
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	while(cas--){
		int n,k;
		cin>>n>>k;
		int a[n],w[k];
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		for(int i=0;i<k;++i){
			cin>>w[i];
		}
		sort(a,a+n,greater<int>());
		sort(w,w+k);
		LL r = 0;
		for(int i=0;i<k;++i){
			r+=a[i];
		}
		int x = k-1;
		for(int i=0;i<k;++i){
			if(w[i]==1) r+=a[i];
			else{
				x+=(w[i]-1);
				r+=a[x];
			}
		}
		cout<<r<<endl;
	}
	return 0;
}