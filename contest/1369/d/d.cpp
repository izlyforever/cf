#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const LL M = 1e9+7;
const int N = 2e6+2;
LL powmod(LL x,LL n){
  LL r(1);
  while(n){
    if(n&1) r=r*x%M;
    n>>=1;  x=x*x%M;
  }
  return r;
}

int main(){
  std::ios::sync_with_stdio(false);std::cin.tie(nullptr);
  int cas;
  cin>>cas;
  LL inv21 = powmod(21,M-2);
  LL a[] = {6,-30,-18};
  while(cas--){
    int n;
    cin>>n;
    LL r = a[n%3];
    r += (n%2==1?14:-14);
    r = (M+r+powmod(2,n+3))*inv21%M;
    cout<<r<<endl;
  }
  return 0;
}