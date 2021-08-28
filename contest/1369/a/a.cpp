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
    cin>>n;
    cout<<(n%4==0?"YES":"NO")<<endl;
  }
  return 0;
}