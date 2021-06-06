#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	while(cas--){
		int n,k;
		cin>>n>>k;
		cout<<2*(k%n!=0)<<endl;
		bool a[n][n]={};
		for(int i=0,x=0,y=0,step=0;i<k;++i){
			a[x++][y++] = 1;
			if(y>=n) y-=n;
			if(x>=n){
				x=0;
				y=++step;
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
