#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
  //freopen("in","r",stdin);
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  int cas;
  cin>>cas;
  while(cas--){
    LL n,r;
    cin>>n>>r;
    if(r<n){
      cout<<(r+1)*r/2<<endl;
    }else{
      cout<<(n-1)*n/2+1<<endl;
    }
  }
  return 0;
}
