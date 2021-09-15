#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  int n;
  while(cin>>n){
    string s;
    cin>>s;
    int l=0,r=0;
    for(auto& c:s){
      if(c=='L'){
        --l;
      }else{
        ++r;
      }
    }
    cout<<(r-l+1)<<endl;
  }
  return 0;
}