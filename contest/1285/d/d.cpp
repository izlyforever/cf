#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL solve(vector<int>& a,int bit){
  if(bit<0) return 0;
  vector<int> l,r;
  for(auto& x:a){
    if((x>>bit)&1) l.push_back(x);
    else r.push_back(x);
  }
  if(l.size()==0) return solve(r,bit-1);
  if(r.size()==0) return solve(l,bit-1);
  return min(solve(l,bit-1),solve(r,bit-1))+(1<<bit);
}
int main(){
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  int n;
  while(cin>>n){
    vector<int> a(n);
    for(auto& x:a) cin>>x;
    cout<<solve(a,30)<<endl;
  }
  return 0;
}
