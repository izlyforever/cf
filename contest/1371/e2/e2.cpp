#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 4002;

int main(){;
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  int n,p;
  cin>>n>>p;
  int a[n];
  for(int i=0;i<n;++i) cin>>a[i];
  int mx = *max_element(a,a+n);
  int bb[n*2+2]={};
  int lx = mx-n;
  int *b = bb - lx; // 黑科技，哈哈
  for(int i=0;i<n;++i) ++b[max(lx,a[i])];
  for(int i=1;i<n*2+2;++i) bb[i]+=bb[i-1];
  int mp[n]={};
  auto modp = [](int x,int p){
    x%=p;
    return x<0?x+p:x;
  };
  for(int i=lx;i<=mx;++i){
    ++mp[modp(i-b[i],p)];
  }
  vector<int> q;
  for(int i=lx;i<=mx;++i){
    if(mp[modp(i,p)]==0){
      q.emplace_back(i);
    }
    --mp[modp(i-b[i],p)];
    ++mp[modp(i+n-b[i+n],p)];
  }
  cout<<q.size()<<endl;
  for(int i=0;i!=q.size();++i){
    cout<<q[i]<<" \n"[i == q.size()-1];
  }
  return 0;
}
