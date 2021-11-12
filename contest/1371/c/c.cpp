#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){;
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  auto f = [](LL a,LL b,LL n,LL m){
    if(a+b<n+m) return false;
    return m<=min(a,b);
  };
  int cas;
  cin>>cas;
  while(cas--){
    LL a,b,n,m;
    cin>>a>>b>>n>>m;
    cout<<(f(a,b,n,m)?"YES":"NO")<<endl;
  }
  return 0;
}
