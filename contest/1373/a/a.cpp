#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){;
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  int cas;
  cin>>cas;
  while(cas--){
    LL a,b,c;
    cin>>a>>b>>c;
    cout<<(a>=c?-1:1)<<" "<<(a*b>c?b:-1)<<endl;
  }
  return 0;
}
