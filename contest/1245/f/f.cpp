#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){;
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  function<int(int,int)> g = [&](int x ,int n)->int{
    int ret = 1,zeros=0;
    for(int i=1;i<=n;i<<=1){
      if(n&i){
        n^=i;
        if(!(x&n)) ret += 1<<zeros;
      }
      if(!(x&i)) ++zeros;
    }
    return ret;
  };
  function<LL(int,int)> f = [&](int l ,int r)->LL{
    if(l==r) return 0;
    LL ret = 0;
    if(l&1){
      ret += (g(l,r)-g(l,l))*2-(l==0);
      ++l;
    }
    if(r&1){
      ret += (g(r-1,r)-g(r-1,l))*2-(r==1);
      --r;
    }
    return ret + 3*f(l/2,r/2);
  };
  int cas;
  cin>>cas;
  while(cas--){
    int l,r;
    cin>>l>>r;
    cout<<f(l,r+1)<<endl;
  }
  return 0;
}
