#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){;
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  int cas;
  cin>>cas;
  while(cas--){
    string s;
    cin>>s;
    bool v[s.size()+1]={};
    int mp=0;
    LL r=0;
    for(int i=0;i!=s.size();++i){
      if(s[i]=='-') ++mp;
      else --mp;
      if(mp>0&&v[mp]==0){
        v[mp] = 1;
        r+=i+1;
      }
    }
    cout<<r+s.size()<<endl;
  }
  return 0;
}
