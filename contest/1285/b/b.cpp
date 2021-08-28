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
    int a[n+1]={0};
    LL dp[n+1]={0},s=0,r=0;
    for(int i=1;i<=n;++i){
      cin>>a[i];
      s+=a[i];
    }
    for(int i=1;i<n;++i){
      dp[i] = dp[i-1]<0?a[i]:dp[i-1]+a[i];
      r = max(r,dp[i]);
    }
    memset(dp,0,sizeof(dp));
    for(int i=2;i<=n;++i){
      dp[i] = dp[i-1]<0?a[i]:dp[i-1]+a[i];
      r = max(r,dp[i]);
    }
    cout<<(r<s?"YES":"NO")<<endl;
  }
  return 0;
}