#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e5+2;
int main(){
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  int n;
  while(cin>>n){
    bool a[N]={};
    int mx=0;
    for(int i=0,x;i<n;++i){
      cin>>x;
      a[x]=1;
      mx = max(mx,x);
    }
    vector<int> p[mx+1];
    int mu[mx+1]={},c[mx+1]={};
    mu[1] = 1;
    for(int i=1;i<=mx;++i){
      p[i].push_back(i);
      for(int j=2*i;j<=mx;j+=i){
        p[j].push_back(i);
        a[i]|=a[j];
        mu[j]-=mu[i];
      }
    }
    stack<int> s;
    LL ans = mx;
    for(int i=mx;i;--i){
      if(a[i]){
        int cop = 0;
        for(auto& x:p[i]) cop+=mu[x]*c[x];
        while(cop){
          for(auto& x:p[s.top()]){
            --c[x];
            if(i%x==0) cop-=mu[x];
          }
          ans = max(ans,LL(i)*s.top());
          s.pop();
        }
        for(auto& x:p[i]) ++c[x];
        s.push(i);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
