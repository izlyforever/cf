#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  LL n;
  while(cin>>n){
    LL r = 1;
    for(LL i=1;i*i<=n;++i){
      if(n%i==0&&__gcd(i,n/i)==1){
        r=i;
      }
    }
    cout<<r<<" "<<n/r<<endl;
  }
  return 0;
}
