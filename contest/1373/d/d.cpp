#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
  //freopen("in","r",stdin);
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  int cas;
  cin>>cas;
  while(cas--){
    int n;
    cin>>n;
    LL a[n];
    LL s = 0;
    for(int i=0;i<n;++i){
      cin>>a[i];
      if(i%2 == 0) s+=a[i];
    }
    vector<LL> b,c;
    for(int i=0;i+1<n;i+=2){
      b.push_back(a[i+1]-a[i]);
    }
    for(int i=1;i+1<n;i+=2){
      c.push_back(a[i]-a[i+1]);
    }
    auto f = [&](vector<LL> &x){
      LL r = 0;
      LL cur = 0;
      for(auto &i:x){
        cur += i;
        r = max(r,cur);
        if(cur<0) cur = 0;
      }
      return r;
    };
    cout<<s+max(f(b),f(c))<<endl;
  }
  return 0;
}
