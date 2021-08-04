#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 4002;

int main(){
  //freopen("in","r",stdin);
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  int n,p;
  cin>>n>>p;
  int a[n];
  for(int i=0;i<n;++i) cin>>a[i];
  sort(a,a+n);
  int cnt[N];
  cnt[0] = 0;
  for(int i=0,j=0;i<N;++i){
    while(j<n&&i==a[j]) ++j;
    cnt[i] = j;
  }
  int mi = a[0];
  for(int i =1;i<n;++i) mi = max(mi,a[i]-i);
  int mx = *max_element(a,a+n);
  vector<int> q;
  for(int x=mi;x<=mx;++x){
    bool flag = true;
    for(int i=0;i<n;++i){
      if((cnt[x+i]-i)%p==0){
        flag = false;break;
      }
    }
    if(flag) q.push_back(x);
  }
  cout<<q.size()<<endl;
  for(int i=0;i!=q.size();++i){
    cout<<q[i]<<" \n"[i == q.size()-1];
  }
  return 0;
}
