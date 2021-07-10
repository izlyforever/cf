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
		vector<int> a,b;
		for(int i=1,x;i<=2*n;++i){
			cin>>x;
			if(x&1) a.push_back(i);
			else b.push_back(i);
		}
		if(a.size()&1){
			for(int i=0;i+1<a.size();i+=2){
				cout<<a[i]<<" "<<a[i+1]<<endl;
			}
			for(int i=0;i+1<b.size();i+=2){
				cout<<b[i]<<" "<<b[i+1]<<endl;
			}
		}else{
			int ia = 0,ib = 2;
			if(a.size()>b.size()) swap(ia,ib);
			for(int i=0;i+ia<a.size();i+=2){
				cout<<a[i]<<" "<<a[i+1]<<endl;
			}
			for(int i=0;i+ib<b.size();i+=2){
				cout<<b[i]<<" "<<b[i+1]<<endl;
			}
		}
	}
	return 0;
}