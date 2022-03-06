#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  LL a,b,c;
  cin>>a>>b>>c;
  cout<<(a!=b)+2*min(a,b)+2*c<<endl;
  return 0;
}
