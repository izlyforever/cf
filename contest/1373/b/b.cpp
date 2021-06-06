#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int cas;
	cin>>cas;
	while(cas--){
		string a;
		cin>>a;
		int l=0,r=0;
		for(auto &c:a){
			if(c=='0') ++l;
			else ++r;
		}
		cout<<(min(l,r)&1?"DA":"NET")<<endl;
	}
	return 0;
}
