#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
  //freopen("in","r",stdin)
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  int cas;
  cin>>cas;
  while(cas--){
    int n;
    string s;
    cin>>n>>s;
    int l=0,r=n-1;
    while(l<n&&s[l]=='0') ++l;
    while(r>=0&&s[r]=='1') --r;
    if(l<r){
      for(int i=0;i<=l;++i){
        cout<<0;
      }
      for(int i=r+1;i<n;++i){
        cout<<1;
      }
      cout<<endl;
    }else{
      cout<<s<<endl;
    }
  }
  return 0;
}