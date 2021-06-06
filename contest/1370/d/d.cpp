#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(auto &x:a) cin>>x;
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
	auto g = [&](int m,bool cur){
		int s = 0;
		for(int i=0;i<n;++i){
			if(cur){
				cur = !cur;
				++s;
			}else{
				if(a[i]<=m){
					++s;
					cur = !cur;
				}
			}
		}
		return s>=k;
	};
	int l = *min_element(a.begin(),a.end());
	int r = *max_element(a.begin(),a.end());
	while(l<=r){
		int m = (l+r)/2;
		if(g(m,0)||g(m,1)) r=m-1;
		else l=m+1;
	}
	cout<<l<<endl;
	return 0;
}