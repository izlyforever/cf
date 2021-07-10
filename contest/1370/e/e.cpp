#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n;
	string s,t;
	cin>>n>>s>>t;
	vector<int> a;
	for(int i=0;i<n;++i){
		if(s[i]==t[i]) continue;
		a.emplace_back(s[i]=='1'?1:-1);
	}
	if(accumulate(a.begin(),a.end(),0)){
		cout<<-1<<endl;
		return 0;
	}
	auto f = [&](int sign){
		int mx = 0,cur=0;
		for(auto &x:a){
			cur += sign*x;
			mx = max(mx,cur);
			cur = max(cur,0);
		}
		return mx;
	};
	cout<<max(f(1),f(-1))<<endl;
	return 0;
}